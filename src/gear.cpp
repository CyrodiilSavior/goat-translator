#include <Arduino.h>
#include <gear.h>

GearManager::GearManager(int shiftA, int shiftB, int TCC) {
    shiftAPin = shiftA;
    shiftBPin = shiftB;
    TCCPin = TCC;
}

GearManager::CommandState GearManager::getCommandState() {
    int currentGear = 0;
    if (solAState == true && solBState == false) {currentGear = 1;}
    if (solAState == true && solBState == true) {currentGear = 2;}
    if (solAState == false && solBState == true) {currentGear = 3;}
    if (solAState == false && solBState == false) {currentGear = 4;}

    return GearManager::CommandState{solAState, solBState, solTCCState, currentGear};
}

void GearManager::commandFirst() {
    solAState = true;
    solBState = false;
    solTCCState = false;
    applyShift();
}

void GearManager::commandSecond() {
    solAState = true;
    solBState = true;
    applyShift();
}

void GearManager::commandThird() {
    solAState = false;
    solBState = true;
    applyShift();
}

void GearManager::commandFourth() {
    solAState = false;
    solBState = false;
    applyShift();
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