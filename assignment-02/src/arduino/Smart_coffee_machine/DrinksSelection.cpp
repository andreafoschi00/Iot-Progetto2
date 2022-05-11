#include "DrinksSelection.h"
#include "IdleController.h"
#include "DrinkPreparation.h"
#include "SelfCheck.h"
#include "Arduino.h"
#include "AssistanceTask.h"
#include "MsgService.h"

#define START 0
#define SELECT 1
#define WAITING 2
#define START_MAKE 3
#define ASSISTANCE 4

extern Drinks* coffee;
extern Drinks* tea;
extern Drinks* chocolate;
String current_selected_drink;

extern Task* assistanceTask;
extern Task* idleController;
extern Task* drinkPreparation;
extern Task* selfCheck;

DrinksSelection::DrinksSelection(LcdDisplay* c_lcd): lcd(c_lcd){
  selector = START;
}

void DrinksSelection::init(){
  pinMode(PIR_PIN, INPUT);
  pinMode(BUTTON_UP, INPUT);
  pinMode(BUTTON_DOWN, INPUT);
  pinMode(BUTTON_MAKE, INPUT);
  currentSelection = 0;
  current_selected_drink = "Coffee";
  sugar_level = map(analogRead(POT_PIN), 0, 1023, 0, SUGAR_QUANT);
  start_time = millis();
}

void DrinksSelection::checkPressedButtons(){
  if(digitalRead(BUTTON_UP)==HIGH){
    btnUpPressed();
    selector = SELECT;
  } else if(digitalRead(BUTTON_DOWN)==HIGH){
    btnDownPressed();
    selector = SELECT;
  }
}

void DrinksSelection::btnUpPressed(){
  switch(currentSelection){
    case 0:{
      current_selected_drink = "Coffee";
      currentSelection = 0;
    }
      
     break;
     case 1:{
      current_selected_drink = "Coffee";
      currentSelection = 0;
    }
     break;
     case 2:{
      current_selected_drink = "Chocolate";
      currentSelection = 1;
    }
     break;
  }
}

void DrinksSelection::checkIfMakeIsPressed(){
  if(digitalRead(BUTTON_MAKE)==HIGH){
      if(current_selected_drink.equals("Coffee")){
        if(coffee->getQuantity() > 0){
          selector = START_MAKE;
          coffee->quantityDecrease();
          MsgService.sendMsg("cm:wk");
          MsgService.sendMsg("cm:teq:"+String(coffee->getQuantity()));
        }else{
          lcd->print("Coffee is unaivable", 1, 1);
          start_time = millis();
        }
      }else if(current_selected_drink.equals("Chocolate")){
        if(chocolate->getQuantity() > 0){
          selector = START_MAKE;
          chocolate->quantityDecrease();
          MsgService.sendMsg("cm:wk");
          MsgService.sendMsg("cm:teq:"+String(chocolate->getQuantity()));
        }else{
          lcd->print("Chocolate is unaivable", 1, 1);
          start_time = millis();
        }     
      }else{
        if(tea->getQuantity() > 0){
          selector = START_MAKE;
          tea->quantityDecrease();
          MsgService.sendMsg("cm:wk");
          MsgService.sendMsg("cm:teq:"+String(tea->getQuantity()));
        }else{
          lcd->print("Tea is unaivable", 1, 1);
          start_time = millis();
        }
      }  
    sugar_level = map(analogRead(POT_PIN), 0, 1023, 0, SUGAR_QUANT);
  }
}

void DrinksSelection::btnDownPressed(){ 
  switch(currentSelection){
    case 0:{
      current_selected_drink = "Chocolate";
      currentSelection = 1;
    }
     break;
     case 1:{
      current_selected_drink = "Tea";
      currentSelection = 2;
    }
     break;
     case 2:{
      current_selected_drink = "Tea";
      currentSelection = 2;
    }
     break;
  }
}

void DrinksSelection::tick(){
  switch(selector){
    case START:{ //Soluzione con ciclo ritenuta inefficiente
      if(coffee->getQuantity() == 0 && chocolate->getQuantity() == 0 && tea->getQuantity() == 0){
        selector = ASSISTANCE;
      } else {
        lcd->print("Ready", 1, 2);
        checkPressedButtons();
        checkIfMakeIsPressed();
      }
    }
    break;
    case SELECT:{
      lcd->print(String(current_selected_drink), 1, 2);
      start_time = millis();
      selector = WAITING;
    }
    break;
    case WAITING:{
      current_time = millis();
      if(current_time - start_time >= TIME_TIMEOUT_BTN_MAKE){
        selector = START;
      }
      checkPressedButtons();
      checkIfMakeIsPressed();
    }
    break;
    case START_MAKE: {
      idleController->setActive(false);
      drinkPreparation->setActive(true);
      selfCheck->setActive(false);
      this->setActive(false);
      selector = START;
    }
    break;
    case ASSISTANCE:
      selector = START;
      idleController->setActive(false);
      this->setActive(false);
      assistanceTask->setActive(true);
      lcd->print("Assistance Required.", 0, 1);
    break;
  }
}
