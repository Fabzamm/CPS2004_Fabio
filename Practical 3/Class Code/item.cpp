#include "item.h"
#include <iostream>

Item::Item(const std::string& name, double price) : name(name), price(price) {}

Item::~Item() {
    // Virtual destructor
}

void Item::display() const {
    std::cout << "Item: " << name << ", Price: $" << price;
}

// Getters and Setters
std::string Item::getName() const {
    return name;
}

void Item::setName(const std::string& name) {
    this->name = name;
}

double Item::getPrice() const {
    return price;
}

void Item::setPrice(double price) {
    this->price = price;
}