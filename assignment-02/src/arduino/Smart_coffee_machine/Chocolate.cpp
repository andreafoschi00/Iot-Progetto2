#include "Chocolate.h"

 Chocolate::Chocolate(){
    name_of_drink = "Chocolate";
 }
  String Chocolate::getName(){
    return name_of_drink;
  }
  
  int Chocolate::getQuantity(){
    return quantity;
  }
  
  void Chocolate::quantityDecrease(){
    if(quantity > 0){
      quantity--;
    }
  }
  
  void Chocolate::refill(){
    quantity = DRINKS_QUANTITY;
  }
