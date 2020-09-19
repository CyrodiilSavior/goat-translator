#ifndef READER_H
#define READER_H

#include "gear.h"

class Reader {
    private:
        int shiftAPin;
        int shiftBPin;
        int TCCPin;    

    public:
        Reader(int solA, int solB, int solTCC);

        int rawShiftA();
        int rawShiftB();
        int rawShiftTCC();

        GearManager::Gear readCommandedGear();
        GearManager::Lockup readConverterCommand();
};

#endif