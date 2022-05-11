#ifndef __BOOTTASK__
#define __BOOTTASK__

#include "Task.h"
#include "LcdDisplay.h"
#include <LiquidCrystal_I2C.h>
#include "config.h"

class BootTask: public Task {
  int state;
  long current_time;
  long initial_time;
  LcdDisplay* lcd;
  
public:
  BootTask(LcdDisplay* c_lcd);
  void init();
  void tick();
};

#endif
