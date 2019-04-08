#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
%attach_1%
#include <syslog.h>
#include <sys/reboot.h>

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
%attach_2%
%attach_3%
    while (1) {
        time_start();
        readAllModbus();
        if (SimulOn)
            readAllSimul();
        else {
%attach_4%
        }
%attach_5%
        Scheme();
        if (SimulOn)
            writeAllSimul();
        else {
%attach_6%
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
