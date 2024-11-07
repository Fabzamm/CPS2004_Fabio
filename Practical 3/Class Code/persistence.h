#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <fstream>
#include "item.h"
#include "grocery.h"
#include "electronics.h"
//#include "clothing.h"
//#include "book.h"
//#include "toy.h"

// Function to restore items from file
Item* restoreFromStringStream(std::ifstream& in);
Item* restoreFromIstream(std::ifstream& in);

#endif // PERSISTENCE_H