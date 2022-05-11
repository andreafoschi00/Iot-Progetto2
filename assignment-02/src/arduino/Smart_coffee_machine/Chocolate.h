#ifndef __CHOCOLATE__
#define __CHOCOLATE__

#include "Arduino.h"
#include "Drinks.h"

class Chocolate: public Drinks {  
 int quantity;
 String name_of_drink;
 
public:
  Chocolate();
  String getName(); 
  int getQuantity();
  void quantityDecrease();
  void refill();
};

#endif
