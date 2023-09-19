#include <iostream>
#include <vector>
#include "Course.h"
using namespace std;
// Hint: use pop_back()
void Course::DropStudent(string last)
{
    /* Type your code here */
}
void Course::PrintCourse()
{
    /* Type your code here */
}
void Course::AddStudent(Student s)
{
    roster.push_back(s);
}
int Course::CountStudents()
{
    return roster.size();
}
