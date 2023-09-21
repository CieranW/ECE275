#include <iostream>
#include <vector>
#include "course.h"
#include "Student.h"
using namespace std;
// Hint: use pop_back()
void Course::DropStudent(string last)
{
    /* Type your code here */
    roster.erase(remove(roster.begin(), roster.end(), last), roster.end());
}
void Course::PrintCourse() const
{
    /* Type your code here */
    for (size_t i = 0; i < roster.size(); i++)
    {
        cout << roster.at(i).GetFirstName() << " " << roster.at(i).GetLastName() << "/" << roster.at(i).GetGPA() << endl;
    }
}
void Course::AddStudent(Student s)
{
    roster.push_back(s);
}
int Course::CountStudents()
{
    return roster.size();
}
