#include "BootTask.h"
#include "Arduino.h"
#include "Coffee.h"
#include "Tea.h"
#include "Chocolate.h"
#include "IdleController.h"
#include "DrinksSelection.h"
#include "SelfCheck.h"

#define WELCOME_INTRO 1
#define MESSAGE_WAITING_TIME 2
#define INIT_DRINKS_QUANTITIES 3
#define READY_STATE 4

extern Task* idleController;
extern Task* drinkSelection;
extern Task* selfCheck;

Drinks* coffee;
Drinks* chocolate;
Drinks* tea;

BootTask::BootTask(LcdDisplay* c_lcd): lcd(c_lcd){
  state = WELCOME_INTRO;
}

void BootTask::init(){
   coffee = new Coffee();
   chocolate = new Chocolate();
   tea = new Tea();    
}

void BootTask::tick(){ 
  switch(state){    
    case WELCOME_INTRO: 
      lcd->initialize();         
      lcd->print("Machine starting....", 1, 2);
      initial_time = millis();
      state = MESSAGE_WAITING_TIME;
    break;
    
    case MESSAGE_WAITING_TIME:    
      current_time = millis();
      if((current_time - initial_time) > INITIAL_MESSAGE_WAITING_TIME){
        state = INIT_DRINKS_QUANTITIES; 
      }     
    break;
    
    case INIT_DRINKS_QUANTITIES:
      coffee->refill();
      chocolate->refill();
      tea->refill();
      state = READY_STATE;
    break;
    
    case READY_STATE:
      lcd->print("READY", 1, 2);
      this->setActive(false);   
      drinkSelection->setActive(true);
      idleController->setActive(true);
      selfCheck->setActive(true);
      state = READY_STATE;
    break;
  }
}
