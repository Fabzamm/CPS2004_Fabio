#include <iostream>
#include <vector>
#include <memory>
#include "Item.h"
#include "Grocery.h"
#include "Electronics.h"

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