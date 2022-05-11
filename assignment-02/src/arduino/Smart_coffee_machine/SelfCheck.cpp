#include "SelfCheck.h"
#include "Arduino.h"
#include "ServoImpl.h"
#include "TempSensorTMP36.h"
#include "Config.h"
#include "DrinksSelection.h"
#include "IdleController.h"

#define INIT 0
#define WAITING 1
#define SELF_CHECKING 2
#define ASSISTANCE_STATE 3

extern ServoMotor* servo;
extern Task* idleController;
extern Task* drinkSelection;
extern Task* assistanceTask;

SelfCheck::SelfCheck(LcdDisplay* c_lcd): lcd(c_lcd) {
  state = INIT;
}

void SelfCheck::init(){
  temp = new TempSensorTMP36(TEMP_PIN);
  pos = 0;
  delta = 1; 
  MsgService.init();
}

void SelfCheck::tick(){
  switch(state){
    case INIT: 
      start_time = millis();
      state = WAITING;
    break;
    case WAITING: 
     current_time = millis();
     if((current_time - start_time >= SELF_CHECK_TIME) && !(digitalRead(PIR_PIN))){
      lcd->print("Initiating Self Test", 2, 1);
      drinkSelection->setActive(false);
      idleController->setActive(false);
      start_time = millis();
      servo->on();
      state = SELF_CHECKING;
     }
    break;
    case SELF_CHECKING: 
        for (pos = 0; pos <= 180; pos += 1) { 
          servo->setPosition(pos);  
          delay(15);  
        }
        for (pos = 180; pos >= 0; pos -= 1) { 
          servo->setPosition(pos); 
          delay(15);
        }
        servo->off();
        temperature = temp->getTemperature();
        if(temperature < TEMP_MIN || temperature > TEMP_MAX) {
          lcd->print("Requesting Assistance.", 0, 1);
          state = ASSISTANCE_STATE;
        } else {
          drinkSelection->setActive(true);
          idleController->setActive(true);
          state = INIT;          
          MsgService.sendMsg("cm:wk");
          MsgService.sendMsg("cm:sf");
        }    
    break;
    case ASSISTANCE_STATE:
      state = INIT;
      this->setActive(false);
      assistanceTask->setActive(true);
    break;
  }
}
