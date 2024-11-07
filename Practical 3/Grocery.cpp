#include "Grocery.h"

Grocery::Grocery(int quantity, double cost, double w)
    : Item(quantity, cost), weight(w) {}

void Grocery::displayInfo() const {
    std::cout << "Item Type: Grocery\n";
    Item::displayInfo();
    std::cout << "Weight: " << weight << " kg\n";
}

// Getter for weight
double Grocery::getWeight() const {
    return weight;
}

// Setter for weight
void Grocery::setWeight(const double w) {
    weight = w;
}

void Grocery::persist(std::ofstream& f){
    f << 0 << qty << price << weight << std::endl;
}