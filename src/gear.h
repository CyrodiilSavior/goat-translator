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

public:
    GearManager(int shiftA, int shiftB, int TCC);

    struct CommandState {
        bool solA;
        bool solB;
        bool TCC;
        int currentGear;
    };

    GearManager::CommandState getCommandState();

    void commandFirst();
    void commandSecond();
    void commandThird();
    void commandFourth();
    void toggleLockup();

};

#endif