#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
    Student();
    Student(string first, string last, double gpa);
    // FIXME: Declare 3 more functions
    string GetFirstName() const;
    string GetLastName() const;
    double GetGPA() const;

private:
    // FIXME: Add 3 private data members
    string firstName;
    string lastName;
    double gpa;
};
#endif /* STUDENT_H_ */