#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include "item.h"

class Electronics : public Item {
private:
    int warrantyYears;

public:
    Electronics(const std::string& name, double price, int warrantyYears);
    
    // Override the display method to include specialized information
    void display() const override;

    void displayInfo() const override;

    void persist(std::ofstream& out) const override;

    int getWarrantyYears() const;
    void setWarrantyYears(int warrantyYears);
};

#endif  // ELECTRONICS_H
