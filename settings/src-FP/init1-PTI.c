    if (SimulOn) {
        if (initAllSimul(CodeSub, drivers, SimulIP, SimulPort))
            return EXIT_FAILURE;
    } else {
        if (initAllDrivers(drivers))
            return EXIT_FAILURE;
    }