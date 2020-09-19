#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>
#include "gear.h"
#include "reader.h"

class Logger {
    private:
        GearManager *myGearManager;
        Reader *myReader;
        
    public:
        Logger(GearManager *gearManager, Reader *reader);
        ~Logger();
        String currentStatus();
};

#endif