#ifndef GROCERY_H
#define GROCERY_H

#include "item.h"
#include <string>
#include <fstream>

class Grocery : public Item {
private:
    std::string expirationDate;
    double weight;

public:
    Grocery(const std::string& name, double price, const std::string& expirationDate, double weight);

    // Override the display method to include specialized information
    void display() const override;

// we need to use the override keyword 
// const to not update the state
    void displayInfo() const override;

    // Getters and Setters for Grocery-specific fields
    std::string getExpirationDate() const;
    void setExpirationDate(const std::string& expirationDate);

    double getWeight() const;
    void setWeight(double weight);

    // Override the persist method to write specialized data
    void persist(std::ofstream& out) const override;
};

#endif  // GROCERY_H
