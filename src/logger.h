#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>
#include "gear.h"

class Logger {
    private:
        GearManager *myGearManager;

    public:
        Logger(GearManager *gearManager);
        ~Logger();
        String currentStatus();
};

#endif