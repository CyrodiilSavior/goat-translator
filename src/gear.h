#ifndef GEARMANAGER_H
#define GEARMANAGER_H

class GearManager {

private:
    int shiftAPin;
    int shiftBPin;
    int TCCPin;

    bool solAState;
    bool solBState;
    bool solTCCState;
    void applyShift();
    void commandFirst();
    void commandSecond();
    void commandThird();
    void commandFourth();
    void toggleLockup();

public:
    typedef int Gear;
    const static Gear FirstGear = 1;
    const static Gear SecondGear = 2;
    const static Gear ThirdGear = 3;
    const static Gear FourthGear = 4;


    GearManager(int shiftA, int shiftB, int TCC);

    struct CommandState {
        bool solA;
        bool solB;
        bool TCC;
        int currentGear;
    };
    void commandGear(Gear commanded);
    GearManager::CommandState getCommandState();

private:
    Gear currentGear;
};

#endif