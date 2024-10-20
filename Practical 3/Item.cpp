#include "Item.h"

// Constructor
Item::Item(int quantity, double cost) : qty(quantity), price(cost) {}

// Display function
void Item::displayInfo() const {
    std::cout << "Quantity: " << qty << "\n";
    std::cout << "Price: $" << price << "\n";
}

// Getters
int Item::getQty() const {
    return qty;
}

double Item::getPrice() const {
    return price;
}

// Setters
void Item::setQty(const int quantity) {
    qty = quantity;
}

void Item::setPrice(const double cost) {
    price = cost;
}
