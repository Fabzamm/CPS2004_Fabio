#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include "Item.h"
#include "Grocery.h"
#include "Electronics.h"

int main() {
    std::vector<std::unique_ptr<Item>> items;

    int option;
    try{
        std::cout<<"Enter the menu option number to select the kind of item: " << std::endl;
        if(!(std::cin>>option)){

            // Display menu
        

            // Sample items
            items.push_back(std::unique_ptr<Grocery>(new Grocery(2, 5.99, 1.5))); // 2 units, $5.99 each, 1.5 kg weight
            items.push_back(std::unique_ptr<Electronics>(new Electronics(1, 299.99))); // 1 unit, $299.99 each

    }
    }catch(int e){}

    // Displaying all items
    std::cout << "Items in the collection:\n";
    for (const auto& item : items) {
        item->displayInfo(); // Requirements for the CORRECT displayInfo() to be called?
        std::cout << "-------------------\n";
    }

    //No more need for the in-memory collection
    /*for (Item* item: items) {
        delete item;
    }*/

    //SAVE ALL TO TEXT FILE
    //Open an output filestream
    //Loop all items inside the -in-mem collection
    //calling item->persist()

    std::ofstream resultFile ("text.txt", std::ofstream::out);

    for (const auto& item : items) {
        item->persist(resultFile);
    }

    resultFile.close();

    return 0;
}