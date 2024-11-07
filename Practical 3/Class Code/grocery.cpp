#include "grocery.h"
#include <iostream>

Grocery::Grocery(const std::string& name, double price, const std::string& expirationDate, double weight)
    : Item(name, price), expirationDate(expirationDate), weight(weight) {}

void Grocery::display() const {
    Item::display();  // Call base class display method for common attributes
    std::cout << ", Expiration Date: " << expirationDate << ", Weight: " << weight << " kg" << std::endl;
}

void Grocery::displayInfo() const {
    std::cout << "Grocery Item Info: " << std::endl;
    std::cout << "Name: " << name << ", Price: $" << price 
              << ", Expiration Date: " << expirationDate 
              << ", Weight: " << weight << " kg" << std::endl;
}


void Grocery::persist(std::ofstream& out) const {
    out << "Grocery\n";
    out << name << "\n " << price << "\n" << expirationDate << "\n" << weight << "\n";
}

// Getters and Setters for Grocery-specific attributes
std::string Grocery::getExpirationDate() const {
    return expirationDate;
}

void Grocery::setExpirationDate(const std::string& expirationDate) {
    this->expirationDate = expirationDate;
}

double Grocery::getWeight() const {
    return weight;
}

void Grocery::setWeight(double weight) {
    this->weight = weight;
}