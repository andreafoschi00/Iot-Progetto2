#include "Arduino.h"
#include "Coffee.h"
#include "Tea.h"
#include "Chocolate.h"
#include "IdleController.h"
#include "DrinksSelection.h"
#include "SelfCheck.h"
#include "AssistanceTask.h"

#define ALERT 0
#define WAIT_FOR_RESPONSE 1
#define RESUME_FUNCTIONALITIES 2

extern Task* idleController;
extern Task* drinkSelection;
extern Task* selfCheck;

extern Drinks* coffee;
extern Drinks* chocolate;
extern Drinks* tea;

AssistanceTask::AssistanceTask(LcdDisplay* c_lcd): lcd(c_lcd){
  state = ALERT;
}

void AssistanceTask::init(){  
   MsgService.init();
}

void AssistanceTask::tick(){ 
  switch(state){    
    case ALERT:  
      MsgService.sendMsg("cm:ss");
      state = WAIT_FOR_RESPONSE;
    break;
    
    case WAIT_FOR_RESPONSE: 
      if(MsgService.isMsgAvailable()) {
          msg = MsgService.receiveMsg();
          if(msg->getContent() == "done"){
              delete msg;
              state = RESUME_FUNCTIONALITIES;     
          }else{
            if(msg->getContent() == "refill"){
               coffee->refill();
               chocolate->refill();
               tea->refill();
               MsgService.sendMsg("cm:cfq:"+String(coffee->getQuantity()));
               MsgService.sendMsg("cm:teq:"+String(tea->getQuantity()));
               MsgService.sendMsg("cm:chq:"+String(chocolate->getQuantity()));
            }                
          }    
      }
    break;
    
    case RESUME_FUNCTIONALITIES:
      MsgService.sendMsg("cm:wk");
      lcd->print("Functionalities resumed", 1, 2); 
      state = ALERT;   
      this->setActive(false);
      idleController->setActive(true);
      drinkSelection->setActive(true);
      selfCheck->setActive(true);
    break;

  }
}
