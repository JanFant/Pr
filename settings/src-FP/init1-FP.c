    nomer = getNomer();
    if (SimulOn) {
        if (initAllSimul(CodeSub, drivers, SimulIP, SimulPort))
            return EXIT_FAILURE;
    } else {
        if (initAllDrivers(drivers)) {
            //Запустились в режиме резервного
            syslog(LOG_INFO, "Mode reserved FP number %d\n", nomer);
            InitInternalParametr();
            master = 0;
            if (initUDP(master, nomer, &setUDP) < 0)
                return EXIT_FAILURE;
            while (initAllDrivers(drivers)) {
                time_start(&tv1);
                readAllModbus();
                reciveVariables();
                MainCycle();
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
    if (initUDP(master, nomer, &setUDP) < 0)
        return EXIT_FAILURE;
    syslog(LOG_INFO, "Mode master FP number %d\n", nomer);