#ifndef __TEA__
#define __TEA__

#include "Arduino.h"
#include "Drinks.h"

class Tea: public Drinks {  
 int quantity;
 String name_of_drink;
 
public:
  Tea();
  String getName(); 
  int getQuantity();
  void quantityDecrease();
  void refill();
};

#endif
