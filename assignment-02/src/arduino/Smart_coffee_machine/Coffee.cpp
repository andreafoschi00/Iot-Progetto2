#include "Coffee.h"

 int quantity;
 String name_of_drink;


 Coffee::Coffee(){
    name_of_drink = "Coffee";
 }
  String Coffee::getName(){
    return name_of_drink;
  }
  
  int Coffee::getQuantity(){
    return quantity;
  }
  
  void Coffee::quantityDecrease(){
    if(quantity > 0){
      quantity--;
    }
  }
  
  void Coffee::refill(){
    quantity = DRINKS_QUANTITY;
  }
