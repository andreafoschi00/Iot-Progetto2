#ifndef __IDLECONTROLLER__
#define __IDLECONTROLLER__

#include "Task.h"
#include <avr/sleep.h>
#include "LcdDisplay.h"
#include <LiquidCrystal_I2C.h>


class IdleController: public Task  {
  LcdDisplay* lcd; 
  long start_time;
  long current_time;
  int pirStat;
  int state;
  
public:
  IdleController(LcdDisplay* lcd); 
  void init();
  void tick();
};

#endif
