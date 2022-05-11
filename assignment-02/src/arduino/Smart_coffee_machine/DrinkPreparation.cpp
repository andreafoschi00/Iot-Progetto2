#include "DrinkPreparation.h"
#include "DrinkEstraction.h"

#define INIT 0
#define MAKING 1
#define FINISHED 2

ServoMotor* servo;
extern String current_selected_drink;

extern Task* drinkEstraction;

DrinkPreparation::DrinkPreparation(LcdDisplay* c_lcd): lcd(c_lcd){
  state = INIT;
}
void DrinkPreparation::init(){
  servo = new ServoImpl(SERVO_PIN);  
  pos=0;
  servo->on();
  servo->setPosition(0);
  delay(1000);
  servo->off();
}

void DrinkPreparation::tick(){
  switch(state){
    case INIT:         
      lcd->print("Making a"+ String(current_selected_drink),1,1);
      servo->on();
      state = MAKING;
      start_time = millis();
    break;
    
    case MAKING:
    progress = millis() - start_time;
    current_time = millis();
    if((current_time - start_time) < TIME_MAKING_DRINK){
      pos = map(progress, 0, TIME_MAKING_DRINK, 0, 180);
      servo->setPosition(pos);
    } else{
      servo->off();
      state = FINISHED;
    }
    break;

    case FINISHED:          
      lcd->print("The "+ String(current_selected_drink), 1, 1);
      lcd->print(" is ready", 2, 1);
      this->setActive(false);
      drinkEstraction->setActive(true);
      state = INIT;
    break;
  }
}
 
