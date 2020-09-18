/**
 * GOAT - Translator (For when you need to talk to goats. How else would you find STEVIE?)
 * Firmware version 0.1.0
 * Author - Garrett Adams (cyrodillsavior@gmail.com)
 * 
 * 
 * Converts GM 4l30e signals into AISIN 30-40le signals
 * Designed to be compatible in non PWM Lockup Isuzu vehicles.
**/                                    

#include <Arduino.h>
#include "logger.h"
#include "gear.h"

#define AISIN_TCC 13
#define AISIN_SHIFT_A 12
#define AISIN_SHIFT_B 11

#define GM_TCC A0
#define GM_SHIFT_A A1
#define GM_SHIFT_B A2

Logger *logger;
GearManager *gearManager;

void setup() {
  Serial.begin(9600);
  pinMode(GM_TCC, INPUT);
  pinMode(GM_SHIFT_A, INPUT);
  pinMode(GM_SHIFT_B, INPUT);  

  pinMode(AISIN_TCC, OUTPUT);
  pinMode(AISIN_SHIFT_A, OUTPUT);
  pinMode(AISIN_SHIFT_B, OUTPUT);  

  //Setup Tools
  gearManager = new GearManager(AISIN_SHIFT_A, AISIN_SHIFT_B, AISIN_TCC);
  logger = new Logger(gearManager);

  //Command First Gear
  gearManager->commandFirst();

}

void loop() {
  
  logger->currentStatus();
  gearManager->commandSecond();
  delay(2000);

  logger->currentStatus();
  gearManager->commandThird();
  delay(2000);

  logger->currentStatus();
  gearManager->toggleLockup();
  delay(2000);

  logger->currentStatus();
  gearManager->commandFourth();
  delay(2000);

  logger->currentStatus();
  gearManager->commandFirst();
  delay(2000);

}