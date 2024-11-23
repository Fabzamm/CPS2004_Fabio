#include "grocery.h"
#include "electronics.h"
//#include "clothing.h"
//#include "book.h"
//#include "toy.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "grocery.h"
#include "electronics.h"
//#include "clothing.h"
//#include "book.h"
//#include "toy.h"
#include "persistence.h"


void displayMenu();
Item* addItem(int type);
void persistCollection(const std::vector<Item*>& shoppingCart, const std::string& filename);
void restoreCollectionFromFile(std::vector<Item*>& shoppingCart, const std::string& filename);