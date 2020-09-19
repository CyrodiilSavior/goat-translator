#include <ArduinoJson.h>
#include "logger.h"
#include "reader.h"

Logger::Logger(GearManager *gearManager, Reader *reader){
   myGearManager = gearManager;
   myReader = reader;
}

String Logger::currentStatus() {
   GearManager::CommandState current = myGearManager->getCommandState(); 

   StaticJsonDocument<200> doc;

   JsonObject state = doc.createNestedObject();
   state["status"] = "normal";
   state["current_gear"] = current.currentGear;
   
   JsonObject gmCommand = state.createNestedObject("gm_input");
   gmCommand["SOL_A"] = myReader->rawShiftA();
   gmCommand["SOL_B"] = myReader->rawShiftB();
   gmCommand["SOL_TCC"] = myReader->rawShiftTCC();

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