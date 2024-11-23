#include "electronics.h"
#include <iostream>

Electronics::Electronics(const std::string& name, double price, int warrantyYears)
    : Item(name, price), warrantyYears(warrantyYears) {}

void Electronics::display() const {
    Item::display();  // Call base class display method for common attributes
    std::cout << ", Warranty: " << warrantyYears << " years" << std::endl;
}

void Electronics::displayInfo() const {
    std::cout << "Electronics Item Info: " << std::endl;
    std::cout << "Name: " << name << ", Price: $" << price 
              << ", Warranty: " << warrantyYears << " years" << std::endl;
}


void Electronics::persist(std::ofstream& out) const {
    out << "Electronics\n";
    out << name << "\n" << price << "\n" << warrantyYears <<  "\n";
}

// Getters and Setters for Electronics-specific attributes
int Electronics::getWarrantyYears() const {
    return warrantyYears;
}

void Electronics::setWarrantyYears(int warrantyYears) {
    this->warrantyYears = warrantyYears;
}
