#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include "Item.h"

class Electronics : public Item {
public:
    Electronics(int quantity, double cost);
    void displayInfo() const override;
};

#endif // ELECTRONICS_H