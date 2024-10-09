#include <iostream>

// Wherever you want to use the namespace, it will be included
using namespace std;

class MyClass { // syntax follows the c syntax for structs

    // attributes functions methods and fields
private:

    string field1;
    int field2;

public:

    // default constructor
    MyClass() : field1("Hello"), field2(2) { // initializer list
        cout << "Default constructor called" <<endl; 
    }

    // parameterized constructor
    MyClass(string field1arg, int field2arg) : field1(field1arg), field2(field2arg) {
        cout << "Parameterized constructor called" <<endl; 
    }

    ~MyClass() {
        cout << "Destructor called" <<endl; 
    }

    // Setters
    void setField1(const string& field1) {
        // in a setter make the argument const to not be updated
        // passed by reference
        this->field1 = field1; // this ptr
    }
    void setField2(const int field2) {
        // in a setter make the argument const to not be updated
        // passed by value since it is a primitive object
        this->field2 = field2; // this ptr
    }

    // Getters
    const string& getField1(){
        return field1;
    }
    const int getField2(){
        return field2;
    }

};

//non-member function
int main(int args, char** argv){
    // std:: is called a namespace
    // allow us to create functions, classes 
    cout << "Hello, from helloWorld!" << endl; //printf() std::ostream

    //Stack
    MyClass myObj1, myObj2("Hello2", 5);
    myObj1.setField1("Hello1");
    myObj1.setField2(2);

    // Exercise - to display the fields of obj1 and obj2 to cout
    // Display fields of myObj1
    /*
    cout << "myObj1.field1: " << myObj1.getField1() << endl;
    cout << "myObj1.field2: " << myObj1.getField2() << endl;
    */
    cout << "myObj1: " << myObj1.getField1() << " " << myObj1.getField2() << endl;

    // Display fields of myObj2
    /*
    cout << "myObj2.field1: " << myObj2.getField1() << endl;
    cout << "myObj2.field2: " << myObj2.getField2() << endl;
    */
    cout << "myObj2: " << myObj2.getField1() << " " << myObj2.getField2() << endl;

    // Heap allocation example (creating an object on the heap)
    MyClass* myObjHeap = new MyClass("HeapObject", 10); // Allocated on the heap ... NOT the modern C++ way !!! raw pointers
    myObjHeap->setField2(4);
    cout << "myObjHeap->field1: " << myObjHeap->getField1() << endl;
    cout << "myObjHeap->field2: " << myObjHeap->getField2() << endl;

    // Deallocate the heap object
    delete myObjHeap; // Calls the destructor for myObjHeap
    myObjHeap = nullptr; //TESTABILITY!!! null and nullptr vs NULL in C

    //int myint2 = myObjHeap->getField2(); //Undefined!!!
    
    // Command Shift P to do the cmake run etc
}