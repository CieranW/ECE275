#include "Student.h"
#include <string>
using namespace std;
// Student class constructor
Student::Student()
{
    firstName = "John";
    lastName = "Doe";
    gpa = 1.0;
}
Student::Student(string first, string last, double gpa)
{
    this->firstName = first;
    this->lastName = last;
    this->gpa = gpa;
}
// FIXME: write 3 more functions
string Student::GetFirstName() const
{
    return firstName;
}

string Student::GetLastName() const
{
    return lastName;
}

double Student::GetGPA() const
{
    return gpa;
}
