#ifndef __DRINKSSELECTION__
#define __DRINKSSELECTION__

#include "Arduino.h"
#include "Task.h"
#include "config.h"
#include "LcdDisplay.h"
#include "Drinks.h"
#include <LiquidCrystal_I2C.h>

class DrinksSelection: public Task {  
 int selector;
 Task* drinkPreparationTask;
 Task* idleTask;
 Task* selfChecktask;
 long start_time;
 long current_time;
 LcdDisplay* lcd;
 int sugar_level;
 int coffeeQuantity;
 int teaQuantity;
 int chocolateQuantity;
 int currentSelection;
 
public:
  DrinksSelection(LcdDisplay* lcd);
  void init();
  void tick();
  void initTasks(Task* t0, Task* t1, Task* t2);
  void checkPressedButtons();
  void btnUpPressed();
  void checkIfMakeIsPressed();
  void btnDownPressed(); 
};

#endif
