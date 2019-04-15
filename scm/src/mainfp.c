#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <syslog.h>
#include <sys/reboot.h>
#include <fp8/misparw.h>
#include <fp8/variables.h>
#include <fp8/modbus-cpc.h>
#include <fp8/netphoto.h>
#include <fp8/UDPTrasport.h>
#include <fp8/drvio.h>

#include "teprLib/allTeprol.h"
#include "master.h"

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

int main(int argc, char **argv) {
    openlog("SUB", LOG_PERROR, LOG_USER);
    if (initVariableTable(allVariables)) {
        syslog(LOG_ERR, "Error init variables\n");
        return EXIT_FAILURE;
    };
    takt = StepCycle / 1000.0;
    InitSetConst();
    initSaver(NameSaveFile, saveVariables, 10);
    initModbusDevices(modbuses);
    initAllregistersModubus();
    initNetPhoto();

    if (SimulOn) {
        if (initAllSimul(CodeSub, drivers, SimulIP, SimulPort))
            return EXIT_FAILURE;
    } else {
        if (initAllDriversPTI(drivers))
            return EXIT_FAILURE;
    }


    while (1) {
        time_start();
        readAllModbus();
        if (SimulOn)
            readAllSimul();
        else {

            readAllDriversPTI();

        }

        Scheme();
        if (SimulOn)
            writeAllSimul();
        else {

            writeAllDriversPTI();
        }

        writeAllModbus();
        makeSaveData();
        long int t = time_cycle();
        if (t > StepCycle) {
            syslog(LOG_INFO, "long cycle %ld\n", t);
        }
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
