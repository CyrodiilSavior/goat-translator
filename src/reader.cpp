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


GearManager::Gear Reader::readCommandedGear(){
    int currentSolA = analogRead(shiftAPin);
    int currentSolB = analogRead(shiftBPin);

    if (currentSolA > 500) {currentSolA = HIGH;} else {currentSolA = LOW;}
    if (currentSolB > 500) {currentSolB = HIGH;} else {currentSolB = LOW;}
    
    if (!currentSolA && currentSolB) {return GearManager::FirstGear;}
    if (currentSolA && currentSolB) {return GearManager::SecondGear;}
    if (currentSolA && !currentSolB) {return GearManager::ThirdGear;}
    if (!currentSolA && !currentSolB) {return GearManager::FourthGear;}
    return GearManager::ThirdGear;
}