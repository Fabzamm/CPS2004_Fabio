#include <iostream>

using namespace std;

// Function that modifies its argument using a reference
void doubleValue(int& num) {
    num *= 2; //dereference operation performed automatically !!!
}
int main() {
    int value = 5;
    
    cout << "Original value: " << value << endl;

    // NOTE: value not &value BUT STILL BY REFERENCE
    doubleValue(value);

    cout << "Value after doubling: " << value << endl;

    return 0;
}
