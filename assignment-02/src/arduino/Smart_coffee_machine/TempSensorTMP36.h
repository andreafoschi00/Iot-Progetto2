#ifndef __TEMP_SENSOR_TMP36__
#define __TEMP_SENSOR_TMP36__

#include "TemperatureSensor.h"

class TempSensorTMP36: public TemperatureSensor {

  public:
      
      TempSensorTMP36(int p);
      virtual float getTemperature();

  private:
      int pin;

};


#endif
