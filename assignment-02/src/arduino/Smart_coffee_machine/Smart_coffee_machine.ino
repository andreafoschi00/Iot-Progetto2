#include "Scheduler.h"
#include "BootTask.h"
#include "IdleController.h"
#include "DrinksSelection.h"
#include "DrinkPreparation.h"
#include "SelfCheck.h"
#include "config.h"
#include "MsgService.h"
#include "AssistanceTask.h"

Scheduler sched;
Task* bootTask;
Task* idleController;
Task* drinkSelection;
Task* drinkPreparation;
Task* drinkEstraction;
Task* selfCheck;
Task* assistanceTask;

void setup(){
  sched.init(50);
  Serial.begin(9600);
  LcdDisplay* lcd = new LcdDisplay();
  
  bootTask = new BootTask(lcd);
  bootTask->init();
  sched.addTask(bootTask);
  bootTask->setActive(true);
  
  idleController = new IdleController(lcd);
  idleController->init();
  sched.addTask(idleController);  
  
  drinkSelection = new DrinksSelection(lcd);
  drinkSelection->init();
  sched.addTask(drinkSelection);

  drinkPreparation = new DrinkPreparation(lcd);
  drinkPreparation->init();
  sched.addTask(drinkPreparation);

  selfCheck = new SelfCheck(lcd);
  selfCheck->init();
  sched.addTask(selfCheck);

  assistanceTask = new AssistanceTask(lcd);
  assistanceTask->init();
  sched.addTask(assistanceTask);
}

void loop(){
  sched.schedule();
}
