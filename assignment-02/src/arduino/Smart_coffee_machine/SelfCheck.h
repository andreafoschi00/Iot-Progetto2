#ifndef __SELFCHECK__
#define __SELFCHECK__

#include "Task.h"
#include "config.h"
#include "LcdDisplay.h"
#include <LiquidCrystal_I2C.h>
#include "Servo.h"
#include "TemperatureSensor.h"
#include "MsgService.h"

class SelfCheck: public Task {
long start_time;
long current_time;
TemperatureSensor* temp;
LcdDisplay* lcd;
int pos;
int state;
int delta;
float temperature;

public:
  SelfCheck(LcdDisplay* lcd);
  void init();
  void tick();
};

#endif
