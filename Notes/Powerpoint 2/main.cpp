/*
* main.cpp
*/
#include <iostream>
#include "student.h"
int main() {
    Student student1("Alice", 20, 3.8);
    Student student2("Bob", 21, 3.6);
    std::cout << "Student 1 details:" << std::endl;
    student1.display();
    std::cout << "Student 2 details:" << std::endl;
    student2.display();
    return 0;
}
