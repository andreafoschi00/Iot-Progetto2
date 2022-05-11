#ifndef __DRINKPREPARATION__
#define __DRINKPREPARATION__

#include "Arduino.h"
#include "Task.h"
#include "config.h"
#include "ServoImpl.h"
#include "LcdDisplay.h"
#include <LiquidCrystal_I2C.h>

class DrinkPreparation: public Task {  
 LcdDisplay* lcd;
 long start_time;
 long current_time;
 int pos;
 int state;
 unsigned long progress;
 
public:
  DrinkPreparation(LcdDisplay* lcd);
  void init();
  void tick();
};

#endif
