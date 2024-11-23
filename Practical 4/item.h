#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <fstream>  // For std::ofstream

// Base Class: Item
class Item {
protected:
    std::string name;
    double price;

public:
    Item(const std::string& name, double price);
    virtual ~Item();

    // Display common item information
    virtual void display() const;  // Method to display common item attributes

    virtual void displayInfo() const = 0;  // Declare polymorphic method
    
    // Persist item data to a file
    virtual void persist(std::ofstream& out) const = 0;  // Pure virtual for persistence

    std::string getName() const;
    void setName(const std::string& name);

    double getPrice() const;
    void setPrice(double price);

};

#endif  // ITEM_H
