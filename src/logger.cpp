#include <ArduinoJson.h>
#include "logger.h"

Logger::Logger(GearManager *gearManager){
   myGearManager = gearManager;
}

String Logger::currentStatus() {
   GearManager::CommandState current = myGearManager->getCommandState(); 

   StaticJsonDocument<200> doc;

   JsonObject state = doc.createNestedObject();
   state["status"] = "normal";
   state["current_gear"] = current.currentGear;
   
   JsonObject gmCommand = state.createNestedObject("gm_input");
   gmCommand["SOL_A"] = false;
   gmCommand["SOL_B"] = false;
   gmCommand["SOL_TCC"] = false;

   JsonObject aisinOutput = state.createNestedObject("aisin_output");
   aisinOutput["SOL_A"] = current.solA;
   aisinOutput["SOL_B"] = current.solB;
   aisinOutput["SOL_TCC"] = current.TCC;

   String outputData = String(serializeJson(state, Serial));
   Serial.println();
   return outputData;
}

Logger::~Logger() {
   delete myGearManager;
}