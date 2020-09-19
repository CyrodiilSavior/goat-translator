#include <Arduino.h>
#include "gear.h"

GearManager::GearManager(int shiftA, int shiftB, int TCC) {
    shiftAPin = shiftA;
    shiftBPin = shiftB;
    TCCPin = TCC;
}

GearManager::CommandState GearManager::getCommandState() {
    return GearManager::CommandState{solAState, solBState, solTCCState, currentGear};
}

void GearManager::commandGear(GearManager::Gear commanded) {
    switch (commanded)
    {
    case 1:
        commandFirst();
        break;
    case 2:
        commandSecond();
        break;
    case 3:
        commandThird();
        break;
    case 4:
        commandFourth();
        break;                
    default:
        commandThird();
        break;
    }
}

void GearManager::commandFirst() {
    solAState = true;
    solBState = false;
    solTCCState = false;
    applyShift();
    currentGear = GearManager::FirstGear;
}

void GearManager::commandSecond() {
    solAState = true;
    solBState = true;
    applyShift();
    currentGear = GearManager::SecondGear;
}

void GearManager::commandThird() {
    solAState = false;
    solBState = true;
    applyShift();
    currentGear = GearManager::ThirdGear;
}

void GearManager::commandFourth() {
    solAState = false;
    solBState = false;
    applyShift();
    currentGear = GearManager::FourthGear;
}

void GearManager::toggleLockup() {
    solTCCState = !solTCCState;
    applyShift();
}

void GearManager::applyShift() {
    digitalWrite(shiftAPin, solAState);
    digitalWrite(shiftBPin, solBState);
    digitalWrite(TCCPin, solTCCState);    
}