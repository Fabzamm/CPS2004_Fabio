#include <iostream>

using namespace std;

int main() {
    double value = 3.14;
    double* ptr = &value; // Pointer to double
    double& ref = value; // Reference to double (constant pointer with less syntactic overheads)

    cout << "Value: " << value << endl;
    cout << "Value through pointer: " << *ptr << endl;
    cout << "Value through reference: " << ref << endl;

    // Update value through pointer and reference
    *ptr = 2.71;
    cout << "Updated value: " << value << endl;

    ref = 1.23;
    cout << "Updated value through reference: " << value << endl;

    int arr[] = {10, 20, 30, 40, 50};
    int* arrPtr = arr;

    cout << "Array elements using pointer arithmetic:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Element " << i << ": " << *arrPtr << endl;
        arrPtr++; // Move to the next element
    }
    
    return 0;
}
