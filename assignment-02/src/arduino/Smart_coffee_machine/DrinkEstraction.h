#ifndef __DRINKESTRACTION__
#define __DRINKESTRACTION__

#include "Task.h"
#include "LcdDisplay.h"
#include <LiquidCrystal_I2C.h>
#include "config.h"
#include "ServoImpl.h"
#include "Sonar.h"

class DrinkEstraction: public Task {
  int state;
  long current_time;
  long start_time;
  LcdDisplay* lcd;
  ServoImpl* servo;
  Sonar* sonar;
  
public:
  DrinkEstraction(LcdDisplay* c_lcd);
  void init();
  void tick();
};

#endif
