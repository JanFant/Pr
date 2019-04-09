    if (SimulOn) {
        if (initAllSimul(CodeSub, drivers, SimulIP, SimulPort))
            return EXIT_FAILURE;
    } else {
        if (initAllDriversPTI(drivers))
            return EXIT_FAILURE;
    }