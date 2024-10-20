#include "Electronics.h"

Electronics::Electronics(int quantity, double cost) 
    : Item(quantity, cost) {}

void Electronics::displayInfo() const {
    std::cout << "Item Type: Electronics\n";
    Item::displayInfo();
}
