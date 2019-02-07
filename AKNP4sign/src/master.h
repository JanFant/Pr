#ifndef AKNP4SIGN_H
#define AKNP4SIGN_H
// Подсистема AKNP4sign:AKNP4sign
static char SimulOn=0;
static short CodeSub=17;
static char SimulIP[]="192.168.1.17\0";
static int SimulPort=5555;
static int StepCycle=5;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 142
static char BUFFER[142];
#include <fp8/UDPTrasport.h>
SetupUDP setUDP = {"192.168.10.55\0", 5432, "192.168.10.155\0", 5432, BUFFER, sizeof(BUFFER),};
int master = 1;
int nomer = 1;
#define R0IN01FS4	 BUFFER[0]	//(VCHSK1) Выход СНМ-11 Гц 
#define idR0IN01FS4	 1	//(VCHSK1) Выход СНМ-11 Гц 
#define R0IN02FS4	 BUFFER[5]	//(VCHSK2) Выход КНК15-1 Гц
#define idR0IN02FS4	 2	//(VCHSK2) Выход КНК15-1 Гц
#define R0IN03FS4	 BUFFER[10]	//(VCHSK3) Выход КНК53М Гц 
#define idR0IN03FS4	 3	//(VCHSK3) Выход КНК53М Гц 
#define AKNP4sign_VCHSK4	 BUFFER[15]	//(VCHSK4)
#define idAKNP4sign_VCHSK4	 4	//(VCHSK4)
#define POWER1	 BUFFER[20]	//(POWER1 )
#define idPOWER1	 5	//(POWER1 )
#define POWER2	 BUFFER[22]	//(POWER2 )
#define idPOWER2	 6	//(POWER2 )
#define DOOR	 BUFFER[24]	//(DOOR   )
#define idDOOR	 7	//(DOOR   )
#define T43	 BUFFER[26]	//(T43    )
#define idT43	 8	//(T43    )
#define T53	 BUFFER[28]	//(T53    )
#define idT53	 9	//(T53    )
#define BP124	 BUFFER[30]	//(BP124  )
#define idBP124	 10	//(BP124  )
#define BP15	 BUFFER[32]	//(BP15   )
#define idBP15	 11	//(BP15   )
#define BP224	 BUFFER[34]	//(BP224  )
#define idBP224	 12	//(BP224  )
#define BP25	 BUFFER[36]	//(BP25   )
#define idBP25	 13	//(BP25   )
#define MPBP124	 BUFFER[38]	//(MPBP124)
#define idMPBP124	 14	//(MPBP124)
#define MPBP15	 BUFFER[40]	//(MPBP15 )
#define idMPBP15	 15	//(MPBP15 )
#define MPBP224	 BUFFER[42]	//(MPBP224)
#define idMPBP224	 16	//(MPBP224)
#define MPBP25	 BUFFER[44]	//(MPBP25 )
#define idMPBP25	 17	//(MPBP25 )
#define R0IE11LS4	 BUFFER[46]	//(VDS32R01) Исправность ВИП 1,6 (№17) СНМ11 4 канала 
#define idR0IE11LS4	 18	//(VDS32R01) Исправность ВИП 1,6 (№17) СНМ11 4 канала 
#define R0IE12LS4	 BUFFER[48]	//(VDS32R02) Исправность ВИП 0,5 (№18) КНК15-1 4 канала
#define idR0IE12LS4	 19	//(VDS32R02) Исправность ВИП 0,5 (№18) КНК15-1 4 канала
#define R0IE13LS4	 BUFFER[50]	//(VDS32R03) Исправность ВИП 0,5 (№19) КНК53М 4 канала 
#define idR0IE13LS4	 20	//(VDS32R03) Исправность ВИП 0,5 (№19) КНК53М 4 канала 
#define VDS32R04	 BUFFER[52]	//(VDS32R04)
#define idVDS32R04	 21	//(VDS32R04)
#define VDS32R05	 BUFFER[54]	//(VDS32R05)
#define idVDS32R05	 22	//(VDS32R05)
#define VDS32R06	 BUFFER[56]	//(VDS32R06)
#define idVDS32R06	 23	//(VDS32R06)
#define VDS32R07	 BUFFER[58]	//(VDS32R07)
#define idVDS32R07	 24	//(VDS32R07)
#define VDS32R08	 BUFFER[60]	//(VDS32R08)
#define idVDS32R08	 25	//(VDS32R08)
#define VDS32R09	 BUFFER[62]	//(VDS32R09)
#define idVDS32R09	 26	//(VDS32R09)
#define VDS32R10	 BUFFER[64]	//(VDS32R10)
#define idVDS32R10	 27	//(VDS32R10)
#define VDS32R11	 BUFFER[66]	//(VDS32R11)
#define idVDS32R11	 28	//(VDS32R11)
#define VDS32R12	 BUFFER[68]	//(VDS32R12)
#define idVDS32R12	 29	//(VDS32R12)
#define VDS32R13	 BUFFER[70]	//(VDS32R13)
#define idVDS32R13	 30	//(VDS32R13)
#define VDS32R14	 BUFFER[72]	//(VDS32R14)
#define idVDS32R14	 31	//(VDS32R14)
#define VDS32R15	 BUFFER[74]	//(VDS32R15)
#define idVDS32R15	 32	//(VDS32R15)
#define VDS32R16	 BUFFER[76]	//(VDS32R16)
#define idVDS32R16	 33	//(VDS32R16)
#define VDS32R17	 BUFFER[78]	//(VDS32R17)
#define idVDS32R17	 34	//(VDS32R17)
#define VDS32R18	 BUFFER[80]	//(VDS32R18)
#define idVDS32R18	 35	//(VDS32R18)
#define VDS32R19	 BUFFER[82]	//(VDS32R19)
#define idVDS32R19	 36	//(VDS32R19)
#define VDS32R20	 BUFFER[84]	//(VDS32R20)
#define idVDS32R20	 37	//(VDS32R20)
#define VDS32R21	 BUFFER[86]	//(VDS32R21)
#define idVDS32R21	 38	//(VDS32R21)
#define VDS32R22	 BUFFER[88]	//(VDS32R22)
#define idVDS32R22	 39	//(VDS32R22)
#define VDS32R23	 BUFFER[90]	//(VDS32R23)
#define idVDS32R23	 40	//(VDS32R23)
#define VDS32R24	 BUFFER[92]	//(VDS32R24)
#define idVDS32R24	 41	//(VDS32R24)
#define VDS32R25	 BUFFER[94]	//(VDS32R25)
#define idVDS32R25	 42	//(VDS32R25)
#define VDS32R26	 BUFFER[96]	//(VDS32R26)
#define idVDS32R26	 43	//(VDS32R26)
#define VDS32R27	 BUFFER[98]	//(VDS32R27)
#define idVDS32R27	 44	//(VDS32R27)
#define VDS32R28	 BUFFER[100]	//(VDS32R28)
#define idVDS32R28	 45	//(VDS32R28)
#define VDS32R29	 BUFFER[102]	//(VDS32R29)
#define idVDS32R29	 46	//(VDS32R29)
#define VDS32R30	 BUFFER[104]	//(VDS32R30)
#define idVDS32R30	 47	//(VDS32R30)
#define VDS32R31	 BUFFER[106]	//(VDS32R31)
#define idVDS32R31	 48	//(VDS32R31)
#define VDS32R32	 BUFFER[108]	//(VDS32R32)
#define idVDS32R32	 49	//(VDS32R32)
#define R0IE02LS4	 BUFFER[110]	//(R0IE02LS4) Отключить питание ПУ, ПР  4 канал
#define idR0IE02LS4	 50	//(R0IE02LS4) Отключить питание ПУ, ПР  4 канал
#define R0IE01LS4	 BUFFER[112]	//(R0IE01LS4) Отключить питание детекторов 4 канала 
#define idR0IE01LS4	 51	//(R0IE01LS4) Отключить питание детекторов 4 канала 
#define FDS16R03	 BUFFER[114]	//(FDS16R03)
#define idFDS16R03	 52	//(FDS16R03)
#define FDS16R04	 BUFFER[116]	//(FDS16R04)
#define idFDS16R04	 53	//(FDS16R04)
#define FDS16R05	 BUFFER[118]	//(FDS16R05)
#define idFDS16R05	 54	//(FDS16R05)
#define FDS16R06	 BUFFER[120]	//(FDS16R06)
#define idFDS16R06	 55	//(FDS16R06)
#define FDS16R07	 BUFFER[122]	//(FDS16R07)
#define idFDS16R07	 56	//(FDS16R07)
#define FDS16R08	 BUFFER[124]	//(FDS16R08)
#define idFDS16R08	 57	//(FDS16R08)
#define R0VN74LZ1	 BUFFER[126]	//(R0VN74LZ1) АС по мощности канал 4 на БАЗ1
#define idR0VN74LZ1	 58	//(R0VN74LZ1) АС по мощности канал 4 на БАЗ1
#define R0VN78LZ1	 BUFFER[128]	//(R0VN78LZ1) АС по периоду разгона канал 4 на БАЗ1
#define idR0VN78LZ1	 59	//(R0VN78LZ1) АС по периоду разгона канал 4 на БАЗ1
#define A0EE01LS4	 BUFFER[130]	//(A0EE01LS4) Исправность АКНП4 на БАЗ1
#define idA0EE01LS4	 60	//(A0EE01LS4) Исправность АКНП4 на БАЗ1
#define A0VN71LS4	 BUFFER[132]	//(A0VN71LS4) Блокировка автоматического подъёма ББ от АКНП4 на БАЗ1
#define idA0VN71LS4	 61	//(A0VN71LS4) Блокировка автоматического подъёма ББ от АКНП4 на БАЗ1
#define R0VN74LZ2	 BUFFER[134]	//(R0VN74LZ2) АС по мощности канал 4 на БАЗ2
#define idR0VN74LZ2	 62	//(R0VN74LZ2) АС по мощности канал 4 на БАЗ2
#define R0VN78LZ2	 BUFFER[136]	//(R0VN78LZ2) АС по периоду разгона канал 4 на БАЗ2
#define idR0VN78LZ2	 63	//(R0VN78LZ2) АС по периоду разгона канал 4 на БАЗ2
#define A1EE01LS4	 BUFFER[138]	//(A1EE01LS4) Исправность АКНП4 на БАЗ2
#define idA1EE01LS4	 64	//(A1EE01LS4) Исправность АКНП4 на БАЗ2
#define A1VN71LS4	 BUFFER[140]	//(A1VN71LS4) Блокировка автоматического подъёма ББ от АКНП4 на БАЗ2
#define idA1VN71LS4	 65	//(A1VN71LS4) Блокировка автоматического подъёма ББ от АКНП4 на БАЗ2
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,8	,1	, &R0IN01FS4},	//(VCHSK1) Выход СНМ-11 Гц 
	{ 2	,8	,1	, &R0IN02FS4},	//(VCHSK2) Выход КНК15-1 Гц
	{ 3	,8	,1	, &R0IN03FS4},	//(VCHSK3) Выход КНК53М Гц 
	{ 4	,8	,1	, &AKNP4sign_VCHSK4},	//(VCHSK4)
	{ 5	,1	,1	, &POWER1},	//(POWER1 )
	{ 6	,1	,1	, &POWER2},	//(POWER2 )
	{ 7	,1	,1	, &DOOR},	//(DOOR   )
	{ 8	,1	,1	, &T43},	//(T43    )
	{ 9	,1	,1	, &T53},	//(T53    )
	{ 10	,1	,1	, &BP124},	//(BP124  )
	{ 11	,1	,1	, &BP15},	//(BP15   )
	{ 12	,1	,1	, &BP224},	//(BP224  )
	{ 13	,1	,1	, &BP25},	//(BP25   )
	{ 14	,1	,1	, &MPBP124},	//(MPBP124)
	{ 15	,1	,1	, &MPBP15},	//(MPBP15 )
	{ 16	,1	,1	, &MPBP224},	//(MPBP224)
	{ 17	,1	,1	, &MPBP25},	//(MPBP25 )
	{ 18	,1	,1	, &R0IE11LS4},	//(VDS32R01) Исправность ВИП 1,6 (№17) СНМ11 4 канала 
	{ 19	,1	,1	, &R0IE12LS4},	//(VDS32R02) Исправность ВИП 0,5 (№18) КНК15-1 4 канала
	{ 20	,1	,1	, &R0IE13LS4},	//(VDS32R03) Исправность ВИП 0,5 (№19) КНК53М 4 канала 
	{ 21	,1	,1	, &VDS32R04},	//(VDS32R04)
	{ 22	,1	,1	, &VDS32R05},	//(VDS32R05)
	{ 23	,1	,1	, &VDS32R06},	//(VDS32R06)
	{ 24	,1	,1	, &VDS32R07},	//(VDS32R07)
	{ 25	,1	,1	, &VDS32R08},	//(VDS32R08)
	{ 26	,1	,1	, &VDS32R09},	//(VDS32R09)
	{ 27	,1	,1	, &VDS32R10},	//(VDS32R10)
	{ 28	,1	,1	, &VDS32R11},	//(VDS32R11)
	{ 29	,1	,1	, &VDS32R12},	//(VDS32R12)
	{ 30	,1	,1	, &VDS32R13},	//(VDS32R13)
	{ 31	,1	,1	, &VDS32R14},	//(VDS32R14)
	{ 32	,1	,1	, &VDS32R15},	//(VDS32R15)
	{ 33	,1	,1	, &VDS32R16},	//(VDS32R16)
	{ 34	,1	,1	, &VDS32R17},	//(VDS32R17)
	{ 35	,1	,1	, &VDS32R18},	//(VDS32R18)
	{ 36	,1	,1	, &VDS32R19},	//(VDS32R19)
	{ 37	,1	,1	, &VDS32R20},	//(VDS32R20)
	{ 38	,1	,1	, &VDS32R21},	//(VDS32R21)
	{ 39	,1	,1	, &VDS32R22},	//(VDS32R22)
	{ 40	,1	,1	, &VDS32R23},	//(VDS32R23)
	{ 41	,1	,1	, &VDS32R24},	//(VDS32R24)
	{ 42	,1	,1	, &VDS32R25},	//(VDS32R25)
	{ 43	,1	,1	, &VDS32R26},	//(VDS32R26)
	{ 44	,1	,1	, &VDS32R27},	//(VDS32R27)
	{ 45	,1	,1	, &VDS32R28},	//(VDS32R28)
	{ 46	,1	,1	, &VDS32R29},	//(VDS32R29)
	{ 47	,1	,1	, &VDS32R30},	//(VDS32R30)
	{ 48	,1	,1	, &VDS32R31},	//(VDS32R31)
	{ 49	,1	,1	, &VDS32R32},	//(VDS32R32)
	{ 50	,1	,1	, &R0IE02LS4},	//(R0IE02LS4) Отключить питание ПУ, ПР  4 канал
	{ 51	,1	,1	, &R0IE01LS4},	//(R0IE01LS4) Отключить питание детекторов 4 канала 
	{ 52	,1	,1	, &FDS16R03},	//(FDS16R03)
	{ 53	,1	,1	, &FDS16R04},	//(FDS16R04)
	{ 54	,1	,1	, &FDS16R05},	//(FDS16R05)
	{ 55	,1	,1	, &FDS16R06},	//(FDS16R06)
	{ 56	,1	,1	, &FDS16R07},	//(FDS16R07)
	{ 57	,1	,1	, &FDS16R08},	//(FDS16R08)
	{ 58	,1	,1	, &R0VN74LZ1},	//(R0VN74LZ1) АС по мощности канал 4 на БАЗ1
	{ 59	,1	,1	, &R0VN78LZ1},	//(R0VN78LZ1) АС по периоду разгона канал 4 на БАЗ1
	{ 60	,1	,1	, &A0EE01LS4},	//(A0EE01LS4) Исправность АКНП4 на БАЗ1
	{ 61	,1	,1	, &A0VN71LS4},	//(A0VN71LS4) Блокировка автоматического подъёма ББ от АКНП4 на БАЗ1
	{ 62	,1	,1	, &R0VN74LZ2},	//(R0VN74LZ2) АС по мощности канал 4 на БАЗ2
	{ 63	,1	,1	, &R0VN78LZ2},	//(R0VN78LZ2) АС по периоду разгона канал 4 на БАЗ2
	{ 64	,1	,1	, &A1EE01LS4},	//(A1EE01LS4) Исправность АКНП4 на БАЗ2
	{ 65	,1	,1	, &A1VN71LS4},	//(A1VN71LS4) Блокировка автоматического подъёма ББ от АКНП4 на БАЗ2
	{-1,0,NULL},
};
static char NameSaveFile[]="AKNP4sign.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_AKNP4sign[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_AKNP4sign[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_AKNP4sign[]={  // 
	{&R0IN01FS4,8,0},	//(R0IN01FS4) R0IN01FS4
	{&R0IN02FS4,8,2},	//(R0IN02FS4) R0IN02FS4
	{&R0IN03FS4,8,4},	//(R0IN03FS4) R0IN03FS4
	{&AKNP4sign_VCHSK4,8,6},	//(AKNP4sign_VCHSK4) AKNP4sign_VCHSK4
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_AKNP4sign[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_AKNP4sign[0],&di_AKNP4sign[0],&ir_AKNP4sign[0],&hr_AKNP4sign[0],NULL,NULL,NULL,0},	 //Пустые сигналы AKNP4sign

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS01[58];	//VCHS01
static vchs_inipar ini_VCHS01={172,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS01={0,0,&ini_VCHS01,buf_VCHS01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS01[]={
	{&R0IN01FS4,8,0},
	{&R0IN02FS4,8,5},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vchs2.h>
static char buf_VCHS02[58];	//VCHS02
static vchs_inipar ini_VCHS02={172,255,1,8,0xff,0,0x1,0x1,0,0,1000000,1000000,};
#pragma pack(push,1)
static table_drv table_VCHS02={0,0,&ini_VCHS02,buf_VCHS02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VCHS02[]={
	{&R0IN03FS4,8,0},
	{&AKNP4sign_VCHSK4,8,5},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/vds32r.h>
static char buf_VDS32[66];	//VDS32
static vds32r_inipar ini_VDS32={0xc2,0xff,0,8,255,255,255,255,255,255,255,255,0,0,0,};
#pragma pack(push,1)
static table_drv table_VDS32={0,0,&ini_VDS32,buf_VDS32,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32[]={
	{&R0IE11LS4,1,0},
	{&R0IE12LS4,1,2},
	{&R0IE13LS4,1,4},
	{&VDS32R04,1,6},
	{&VDS32R05,1,8},
	{&VDS32R06,1,10},
	{&VDS32R07,1,12},
	{&VDS32R08,1,14},
	{&VDS32R09,1,16},
	{&VDS32R10,1,18},
	{&VDS32R11,1,20},
	{&VDS32R12,1,22},
	{&VDS32R13,1,24},
	{&VDS32R14,1,26},
	{&VDS32R15,1,28},
	{&VDS32R16,1,30},
	{&VDS32R17,1,32},
	{&VDS32R18,1,34},
	{&VDS32R19,1,36},
	{&VDS32R20,1,38},
	{&VDS32R21,1,40},
	{&VDS32R22,1,42},
	{&VDS32R23,1,44},
	{&VDS32R24,1,46},
	{&VDS32R25,1,48},
	{&VDS32R26,1,50},
	{&VDS32R27,1,52},
	{&VDS32R28,1,54},
	{&VDS32R29,1,56},
	{&VDS32R30,1,58},
	{&VDS32R31,1,60},
	{&VDS32R32,1,62},
	{NULL,0,0},
};
#pragma pop
#include <fp8/drivers/fds16r.h>
static char buf_FDS16[40];	//FDS16
static fds16r_inipar ini_FDS16={0x04,0xff,8,8,0xff,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_FDS16={0,0,&ini_FDS16,buf_FDS16,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_FDS16[]={
	{&R0IE02LS4,1,0},
	{&R0IE01LS4,1,2},
	{&FDS16R03,1,4},
	{&FDS16R04,1,6},
	{&FDS16R05,1,8},
	{&FDS16R06,1,10},
	{&FDS16R07,1,12},
	{&FDS16R08,1,14},
	{&R0VN74LZ1,1,16},
	{&R0VN78LZ1,1,18},
	{&A0EE01LS4,1,20},
	{&A0VN71LS4,1,22},
	{&R0VN74LZ2,1,24},
	{&R0VN78LZ2,1,26},
	{&A1EE01LS4,1,28},
	{&A1VN71LS4,1,30},
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
	{0xc4,0x01,12,58,def_buf_VCHS01,&table_VCHS01}, //VCHS01
	{0xc4,0x02,12,58,def_buf_VCHS02,&table_VCHS02}, //VCHS02
	{0xc2,0x04,15,66,def_buf_VDS32,&table_VDS32}, //VDS32
	{0x04,0x05,20,40,def_buf_FDS16,&table_FDS16}, //FDS16
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
