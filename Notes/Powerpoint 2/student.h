/*
* student.h
*/
#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student {
public:
 Student(const std::string& name, int age, double avg); //Constructor
 void display() const;

private:
 std::string name;
 int age;
 double avg;
};

#endif // STUDENT_H
