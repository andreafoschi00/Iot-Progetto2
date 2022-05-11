#include "DrinkEstraction.h"
#include "Arduino.h"
#include "DrinksSelection.h"
#include "SelfCheck.h"

#define EXTRACTION_MESSAGE 0
#define WAIT 1
#define RESET_STATE 2
#define END_TASK 3

extern Task* drinkSelection;
extern Task* selfCheck;

DrinkEstraction::DrinkEstraction(LcdDisplay* c_lcd): lcd(c_lcd){
 state = EXTRACTION_MESSAGE;
}

void DrinkEstraction::init(){
   servo = new ServoImpl(SERVO_PIN);
   sonar = new Sonar(SONAR_ECHO_PIN, SONAR_TRIG_PIN);
}

void DrinkEstraction::tick(){ 
  switch(state){
    case EXTRACTION_MESSAGE:
      selfCheck->setActive(false);
      lcd->print("Please extract the drink.",1,2);
      start_time = millis();
      state = WAIT;
    break;

    case WAIT:
      current_time = millis();
      if((current_time - start_time >= TIME_WAITING_EXTRACTION) || (sonar->getDistance() >= DISTANCE_FOR_DRINK_EXTRACTION)){
        lcd->print("Thanks and goodbye.",1,2);
        state = RESET_STATE;
      }
    break;

    case RESET_STATE:
      servo->on();
      servo->setPosition(0);
      delay(1000);
      servo->off();
      state = END_TASK;
    break;

    case END_TASK:
      this->setActive(false);
      drinkSelection->setActive(true);
      selfCheck->setActive(true);
      state = EXTRACTION_MESSAGE;
    break;
  }
}
