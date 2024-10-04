/*
* student.cpp
*/
#include "student.h"
#include <iostream>
#include <iomanip>

Student::Student(const std::string& name, int age, double avg) //member method
    : name(name), age(age), avg(avg) {}

void Student::display() const {
    std::cout << "Name: " << name << ", Age: " << age << ", Avg: " << std::fixed << std::setprecision(2) << avg << std::endl;
}
