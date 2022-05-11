#ifndef __ASSISTANCETASK__
#define __ASSISTANCETASK__

#include "Task.h"
#include "LcdDisplay.h"
#include <LiquidCrystal_I2C.h>
#include "config.h"
#include "MsgService.h"

class AssistanceTask: public Task {
  int state;
  LcdDisplay* lcd;
  Msg* msg;
  
public:
  AssistanceTask(LcdDisplay* c_lcd);
  void init();
  void tick();
};

#endif
