#ifndef COURSE_H
#define COURSE_H
#include <vector>
#include "Student.h"
class Course
{
public:
    void DropStudent(string last);
    void AddStudent(Student s);
    int CountStudents();
    void PrintCourse() const;

private:
    // collection of Student objects
    vector<Student> roster;
};
#endif
