#ifndef __COFFEE__
#define __COFFEE__

#include "Arduino.h"
#include "Drinks.h"

class Coffee: public Drinks {  
 int quantity;
 String name_of_drink;
 
public:
  Coffee();
  String getName(); 
  int getQuantity();
  void quantityDecrease();
  void refill();
};

#endif
