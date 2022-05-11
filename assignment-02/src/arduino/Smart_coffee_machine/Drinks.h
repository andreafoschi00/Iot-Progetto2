#ifndef __DRINKS__
#define __DRINKS__

#include "config.h"

class Drinks {
  
public:  
         
  virtual String getName() = 0;
  
  virtual int getQuantity() = 0;
  
  virtual void quantityDecrease() = 0;

  virtual void refill() = 0;
  
};

#endif
