#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item {
protected:
    int qty;
    double price;

public:
    Item(int quantity, double cost);

    virtual ~Item() = default;
    virtual void displayInfo() const;

    //Getters
    int getQty() const;
    double getPrice() const;

    //Setters
    void setQty(const int quantity);
    void setPrice(const double cost);
};

#endif // ITEM_H