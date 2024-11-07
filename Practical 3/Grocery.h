#ifndef GROCERY_H
#define GROCERY_H

#include "Item.h"

class Grocery : public Item {
private:
    double weight; // Weight in kilograms

public:
    Grocery(int quantity, double cost, double w);
    void displayInfo() const override;
    void persist(std::ofstream& f) override;

    // Getter for weight
    double getWeight() const;

    // Setter for weight
    void setWeight(const double w);
};

#endif // GROCERY_H