            if (isSlave()) {
                syslog(LOG_ERR, "Lost master \n");
                break;
            }
            if (readAllDrivers() != 0)
                break;