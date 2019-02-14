#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <fp8/misparw.h>
#include <fp8/variables.h>
#include <fp8/modbus-cpc.h>
#include <fp8/drvio.h>
#include <fp8/netphoto.h>
#include <fp8/UDPTrasport.h>
#include <syslog.h>

#include "teprLib/allTeprol.h"

#include "master.h"
#include <sys/reboot.h>

void doWork() {
    char b;
    short s;
    int ii;
    float f;
    long long int l;
    double d;
    for (int i = 0; i < 1000; i++) {
        VarCtrl *vc = findVariable(i);
        if (vc == NULL) continue;
        switch (vc->format) {
            case boolean:
                b = getAsBool(i);
                b = (b) ? 0 : 1;
                setAsBool(i, b);
                break;
            case char1b:
                b = getAsBool(i);
                b++;
                setAsBool(i, b);
                break;
            case uint2b:
            case sint2b:
                s = getAsShort(i);
                s += 1;
                setAsShort(i, s);
                break;
            case uint4b:
            case sint4b:
                ii = getAsInt(i);
                ii++;
                setAsInt(i, ii);
                break;
            case float4b:
                f = getAsFloat(i);
                f += 1.1;
                setAsFloat(i, f);
                break;
            case sint8b:
                l = getAsLong(i);
                l += 1;
                setAsLong(i, l);
                break;
            case float8b:
                d = getAsDouble(i);
                d += 1.000001;
                setAsDouble(i, d);
                break;
        }

    }
}
//struct timezone tzone;
static struct timeval tv1, tv2, dtv;

void time_start() {
    gettimeofday(&tv1, NULL);
}

void takt_time_cycle() {
    gettimeofday(&tv2, NULL);
    dtv.tv_sec = tv2.tv_sec - tv1.tv_sec;
    dtv.tv_usec = tv2.tv_usec - tv1.tv_usec;
    if (dtv.tv_usec < 0) {
        dtv.tv_sec--;
        dtv.tv_usec += 1000000;
    }
    takt = (float) dtv.tv_sec + ((float) dtv.tv_usec / 1000000.0);
}

long int time_cycle() {
    gettimeofday(&tv2, NULL);
    dtv.tv_sec = tv2.tv_sec - tv1.tv_sec;
    dtv.tv_usec = tv2.tv_usec - tv1.tv_usec;
    if (dtv.tv_usec < 0) {
        dtv.tv_sec--;
        dtv.tv_usec += 1000000;
    }
    return dtv.tv_sec * 1000 + dtv.tv_usec / 1000;
}

int main(int argc, char** argv) {
    openlog("SUB", LOG_PERROR, LOG_USER);
    if (initVariableTable(allVariables)) {
        syslog(LOG_ERR, "Error init variables\n");
        return EXIT_FAILURE;
    };
    //    doWork();
    takt = StepCycle / 1000;
    InitSetConst();
    initSaver(NameSaveFile, saveVariables,10);
    initModbusDevices(modbuses);
    initAllregistersModubus();
    initNetPhoto();
    nomer = getNomer();
    if (SimulOn) {
        if (initAllSimul(CodeSub, drivers, SimulIP, SimulPort)) return EXIT_FAILURE;
    } else {
        if (initAllDrivers(drivers)) {
            //Запустились в режиме резервного 
            syslog(LOG_INFO, "Mode reserved FP number %d\n", nomer);
            master = 0;
            if (initUDP(master, nomer, &setUDP) < 0) return EXIT_FAILURE;
            while (initAllDrivers(drivers)) {
                time_start();
                readAllModbus();
                reciveVariables();
                writeAllModbus();
                long int t = time_cycle();
                if (t > StepCycle) {
                    syslog(LOG_INFO, "long cycle %ld\n", t);
                }
                while ((time_cycle() + 1) < StepCycle) {
                    makeStepModbusDevices();
                }
                while ((time_cycle()) < StepCycle) {
                }
            }
            closeUDP();
        };
    }
    // Режим основного ФП
    master = 1;
    if (initUDP(master, nomer, &setUDP) < 0) return EXIT_FAILURE;
    syslog(LOG_INFO, "Mode master FP number %d\n", nomer);
    init_dataVchs(buf_VCHS01);
    init_dataVchs(buf_VCHS02);
    while (1) {
        time_start();
        readAllModbus();
        if (SimulOn) readAllSimul();
        else {
            if (isSlave()) {
                syslog(LOG_ERR, "Lost master \n");
            break;
            }
            if (readAllDrivers() != 0) break;
        }
        VCHS_post(buf_VCHS01);
        VCHS_post(buf_VCHS02);
        Scheme(); //!!! Схема!
        sendVariables();
        if (SimulOn) writeAllSimul();
        else {
            if (writeAllDrivers() != 0) break;
        }
        writeAllModbus();
        makeSaveData();
        long int t = time_cycle();
        if (t > StepCycle) {
            syslog(LOG_INFO, "long cycle %ld\n", t);
        }
        sendVariables();
        while ((time_cycle() + 1) < StepCycle) {
            makeStepModbusDevices();
        }
        while ((time_cycle()) < StepCycle) {
        }
        takt_time_cycle();
    }
    stopNetPhoto();
    sync();
    syslog(LOG_INFO, "exiting programm");
    closelog();
    return (EXIT_SUCCESS);

    //    reboot(RB_AUTOBOOT);
}
