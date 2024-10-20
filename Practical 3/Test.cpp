#include <iostream>
#include <vector>
#include <string>
#include <memory>

// Base class Item
class Item {
protected:
    int qty;
    double price;

public:
    Item(int quantity, double cost) : qty(quantity), price(cost) {}

    virtual ~Item() = default;

    virtual void displayInfo() const {
        std::cout << "Quantity: " << qty << "\n";
        std::cout << "Price: $" << price << "\n";
    }
};

// Grocery class, derived from Item
class Grocery : public Item {
private:
    double weight; // Weight in kilograms

public:
    Grocery(int quantity, double cost, double w) 
        : Item(quantity, cost), weight(w) {}

    void displayInfo() const override {
        std::cout << "Item Type: Grocery\n";
        Item::displayInfo();
        std::cout << "Weight: " << weight << " kg\n";
    }
};

// Electronics class, derived from Item (details to be filled later)
class Electronics : public Item {
public:
    Electronics(int quantity, double cost) 
        : Item(quantity, cost) {}

    void displayInfo() const override {
        std::cout << "Item Type: Electronics\n";
        Item::displayInfo();
    }
};

// Function to add and display items
int main() {
    std::vector<std::unique_ptr<Item>> items;

    // Sample items
    items.push_back(std::unique_ptr<Grocery>(new Grocery(2, 5.99, 1.5))); // 2 units, $5.99 each, 1.5 kg weight
    items.push_back(std::unique_ptr<Electronics>(new Electronics(1, 299.99))); // 1 unit, $299.99 each

    // Displaying all items
    std::cout << "Items in the collection:\n";
    for (const auto& item : items) {
        item->displayInfo();
        std::cout << "-------------------\n";
    }

    return 0;
}
