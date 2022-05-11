#include "IdleController.h"
#include "Arduino.h"
#include "config.h"
#include "DrinksSelection.h"

#define IDLE_MODE 0
#define ACTIVE 1
#define SLEEP 2

extern long time_last_btn_pressed;
extern Task* drinkSelection;;

void wakeUp(){}

IdleController::IdleController(LcdDisplay* c_lcd): lcd(c_lcd){
  state = IDLE_MODE;   
}

void IdleController::init(){
  delay(1000);
  start_time = millis();
}

void IdleController::tick(){
  switch(state){
    case IDLE_MODE: {
      current_time = millis();
      if(!digitalRead(PIR_PIN) && ((current_time - start_time) >= IDLE_TIME)){
        state = SLEEP;
      } else if(digitalRead(PIR_PIN)){
        state = ACTIVE;
      }
    }
    break;
    case ACTIVE: {
      if(!digitalRead(PIR_PIN)){
        state = IDLE_MODE;
        start_time = millis();
      }
    }
    break;
    case SLEEP: {
        drinkSelection->setActive(false);
        lcd->getLcd().clear();
        lcd->getLcd().noBacklight();
        attachInterrupt(digitalPinToInterrupt(PIR_PIN), wakeUp, RISING);
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();
        sleep_mode();
        Serial.println("Wake up");
        sleep_disable();
        detachInterrupt(PIR_PIN);
        lcd->getLcd().backlight();
        drinkSelection->setActive(true);
        Serial.println("Going active");
        state = ACTIVE;
    }
    break;
  }
}
 
