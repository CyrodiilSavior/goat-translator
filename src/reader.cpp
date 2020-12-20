#include <Arduino.h>
#include "reader.h"
#include "gear.h"

Reader::Reader(int solA, int solB, int solTCC){
    shiftAPin = solA;
    shiftBPin = solB;
    TCCPin = solTCC;
}

int Reader::rawShiftA(){
    return analogRead(shiftAPin);
}

int Reader::rawShiftB(){
    return analogRead(shiftBPin);
}

int Reader::rawShiftTCC(){
    return analogRead(TCCPin);
}

GearManager::Lockup Reader::readConverterCommand(){
    if (rawShiftTCC() > 25) {return GearManager::Locked;} else {return GearManager::Unlocked;}
}


GearManager::Gear Reader::readCommandedGear(){
    int currentSolA = rawShiftA();
    int currentSolB = rawShiftB();

    if (currentSolA > 25) {currentSolA = HIGH;} else {currentSolA = LOW;}
    if (currentSolB > 25) {currentSolB = HIGH;} else {currentSolB = LOW;}
    
    if (!currentSolA && currentSolB) {return GearManager::FirstGear;}
    if (currentSolA && currentSolB) {return GearManager::SecondGear;}
    if (currentSolA && !currentSolB) {return GearManager::ThirdGear;}
    if (!currentSolA && !currentSolB) {return GearManager::FourthGear;}
    return GearManager::ThirdGear;
}