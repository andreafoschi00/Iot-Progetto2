#ifndef __LCD__
#define __LCD__
#include <LiquidCrystal_I2C.h> 

class LcdDisplay{ 
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
  
  public:
    void initialize();
    void print(String msg, int row, int column);
    LiquidCrystal_I2C getLcd();   
};

#endif
