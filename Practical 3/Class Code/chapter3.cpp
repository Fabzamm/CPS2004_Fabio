#include "chapter3.h"

// Function to save the collection to a file
void persistCollection(const std::vector<Item*>& shoppingCart, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing.\n";
        return;
    }
    for (const auto& item : shoppingCart) {
        item->persist(outFile);
    }
    outFile.close();
    std::cout << "Shopping cart saved to " << filename << std::endl;
}


// Function to restore the collection from a file (using >> approach)
void restoreCollectionFromFile(std::vector<Item*>& shoppingCart, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    while (!inFile.eof()) {
        Item* newItem = restoreFromStringStream(inFile);  // Use restoreFromStringStream for the second approach
        if (newItem != nullptr) {
            shoppingCart.push_back(newItem);
        }
    }

    inFile.close();
    std::cout << "Shopping cart restored from " << filename << std::endl;
}

void displayMenu() {
    std::cout << "Choose item type to add:\n";
    std::cout << "1. Grocery\n";
    std::cout << "2. Electronics\n";
    std::cout << "3. Clothing\n";
    std::cout << "4. Book\n";
    std::cout << "5. Toy\n";
    std::cout << "6. Exit\n";
};

Item* addItem(int type) {
    std::string name;
    double price;
    
    std::cout << "Enter the item name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter the price: ";
    std::cin >> price;

    switch (type) {
        case 1: {  // Grocery
            std::string expirationDate;
            double weight;
            std::cout << "Enter the expiration date: ";
            std::cin.ignore();
            std::getline(std::cin, expirationDate);
            std::cout << "Enter the weight (kg): ";
            std::cin >> weight;
            return new Grocery(name, price, expirationDate, weight);
        }
        case 2: {  // Electronics
            int warrantyYears;
            std::cout << "Enter the warranty years: ";
            std::cin >> warrantyYears;
            return new Electronics(name, price, warrantyYears);
        }
        // case 3: {  // Clothing
        //     std::string size, fabric;
        //     std::cout << "Enter the size: ";
        //     std::cin.ignore();
        //     std::getline(std::cin, size);
        //     std::cout << "Enter the fabric type: ";
        //     std::getline(std::cin, fabric);
        //     return new Clothing(name, price, size, fabric);
        // }
        // case 4: {  // Book
        //     std::string author;
        //     int pages;
        //     std::cout << "Enter the author's name: ";
        //     std::cin.ignore();
        //     std::getline(std::cin, author);
        //     std::cout << "Enter the number of pages: ";
        //     std::cin >> pages;
        //     return new Book(name, price, author, pages);
        // }
        // case 5: {  // Toy
        //     int ageRecommendation;
        //     std::cout << "Enter the age recommendation: ";
        //     std::cin >> ageRecommendation;
        //     return new Toy(name, price, ageRecommendation);
        // }
        default:
            std::cout << "Invalid type.\n";
            return nullptr;
    }
}

int main() {
    std::string filename = "shopping_cart.txt";
    std::vector<Item*> shoppingCart;

    // Try to restore the collection from the file
    restoreCollectionFromFile(shoppingCart, filename);

    int choice;
    while (true) {
        displayMenu();  // Display the menu
        std::cout << "Enter your choice (1-6): ";
        std::cin >> choice;

        if (choice == 6) {  // Exit condition
            break;
        }

        Item* newItem = addItem(choice);  // Add the item based on the choice
        if (newItem) {
            shoppingCart.push_back(newItem);
            std::cout << "Item added.\n";
        } else {
            std::cout << "Invalid choice or failed to add item.\n";
        }
    }

    // Display information about all items in the shopping cart
    std::cout << "\nShopping Cart Items:\n";
    for (const auto& item : shoppingCart) {
        item->displayInfo();  // Call displayInfo for each item
    }
    
    // Save the collection to a file on exit
    persistCollection(shoppingCart, filename);

// no more need for the in memory collection
    // Clean up memory
    for (auto& item : shoppingCart) {
        delete item;
    }

    return 0;
}
