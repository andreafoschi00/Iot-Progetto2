#include "Tea.h"

 Tea::Tea(){
    name_of_drink = "Tea";
 }
  String Tea::getName(){
    return name_of_drink;
  }
  
  int Tea::getQuantity(){
    return quantity;
  }
  
  void Tea::quantityDecrease(){
    if(quantity > 0){
      quantity--;
    }
  }
  
  void Tea::refill(){
    quantity = DRINKS_QUANTITY;
  }
