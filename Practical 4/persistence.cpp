#include <fstream>
#include <sstream>
#include <string>
#include "grocery.h"
#include "electronics.h"
// #include "clothing.h"
// #include "book.h"
// #include "toy.h"
#include "persistence.h"

// Function to restore an Item* from file using `>>` operator
Item* restoreFromIstream(std::ifstream& in) {
    std::string type;
    in >> type;  // Read the object type

    if (type == "Grocery") {
        std::string name, expirationDate;
        double price, weight;
        in.ignore();  // To skip the newline after the type
        std::getline(in, name);  // Read name
        in >> price >> expirationDate >> weight;  // Read other attributes
        return new Grocery(name, price, expirationDate, weight);
    } else if (type == "Electronics") {
        std::string name;
        double price;
        int warrantyYears;
        in.ignore();
        std::getline(in, name);
        in >> price >> warrantyYears;
        return new Electronics(name, price, warrantyYears);
    }
    // } else if (type == "Clothing") {
    //     std::string name, size, fabric;
    //     double price;
        // in.ignore();
    //     std::getline(in, name);
    //     in >> price;
    //     in.ignore();
    //     std::getline(in, size);
    //     std::getline(in, fabric);
    //     return new Clothing(name, price, size, fabric);
    // } else if (type == "Book") {
    //     std::string name, author;
    //     double price;
    //     int pages;
    //     in.ignore();
    //     std::getline(in, name);
    //     in >> price;
    //     in.ignore();
    //     std::getline(in, author);
    //     in >> pages;
    //     return new Book(name, price, author, pages);
    // } else if (type == "Toy") {
    //     std::string name;
    //     double price;
    //     int ageRecommendation;
    //     in.ignore();
    //     std::getline(in, name);
    //     in >> price >> ageRecommendation;
    //     return new Toy(name, price, ageRecommendation);
    // }

    return nullptr;  // Return nullptr if unknown type is encountered
};

Item* restoreFromStringStream(std::ifstream& in) {
    std::string type;
    std::getline(in, type);  // Read the object type as a line

    if (type == "Grocery") {
        std::string name, expirationDate;
        double price, weight;
        std::getline(in, name);  // Read name
        std::string line;
        
        std::getline(in, line);
        std::istringstream(line) >> price;  // Parse price from line

        std::getline(in, expirationDate);  // Read expiration date

        std::getline(in, line);
        std::istringstream(line) >> weight;  // Parse weight from line

        return new Grocery(name, price, expirationDate, weight);
    } else if (type == "Electronics") {
        std::string name;
        double price;
        int warrantyYears;
        std::getline(in, name);
        std::string line;
        
        std::getline(in, line);
        std::istringstream(line) >> price;  // Parse price from line
        
        std::getline(in, line);
        std::istringstream(line) >> warrantyYears;  // Parse warranty years

        return new Electronics(name, price, warrantyYears);
    }
    // } else if (type == "Clothing") {
    //     std::string name, size, fabric;
    //     double price;
    //     std::getline(in, name);
        
    //     std::string line;
    //     std::getline(in, line);
    //     std::istringstream(line) >> price;  // Parse price

    //     std::getline(in, size);
    //     std::getline(in, fabric);

    //     return new Clothing(name, price, size, fabric);
    // } else if (type == "Book") {
    //     std::string name, author;
    //     double price;
    //     int pages;
    //     std::getline(in, name);
        
    //     std::string line;
    //     std::getline(in, line);
    //     std::istringstream(line) >> price;  // Parse price

    //     std::getline(in, author);
        
    //     std::getline(in, line);
    //     std::istringstream(line) >> pages;  // Parse pages

    //     return new Book(name, price, author, pages);
    // } else if (type == "Toy") {
    //     std::string name;
    //     double price;
    //     int ageRecommendation;
    //     std::getline(in, name);
        
    //     std::string line;
    //     std::getline(in, line);
    //     std::istringstream(line) >> price;  // Parse price

    //     std::getline(in, line);
    //     std::istringstream(line) >> ageRecommendation;  // Parse age recommendation

    //     return new Toy(name, price, ageRecommendation);
    // }

    return nullptr;  // Return nullptr if unknown type
};