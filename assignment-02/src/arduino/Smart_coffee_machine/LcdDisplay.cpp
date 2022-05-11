#include "LcdDisplay.h"
#include "Arduino.h"
#include <LiquidCrystal_I2C.h> 

void LcdDisplay::initialize(){
    lcd.init();
    lcd.backlight();
}

void LcdDisplay::print(String msg, int row, int column){
    lcd.clear();
    lcd.setCursor(column, row);
    lcd.print(msg);
}

LiquidCrystal_I2C LcdDisplay::getLcd(){
  return lcd;
}
