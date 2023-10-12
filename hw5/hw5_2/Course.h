#ifndef COURSEH
#define COURSEH

#include <iostream>
#include <string>

using namespace std;

class Course
{
    // TODO: Declare private data members
private:
    string courseNumber;
    string courseTitle;

public:
    // TODO: Declare mutator functions SetCourseNumber(), SetCourseTitle()
    void SetCourseNumber(string courseNumber);
    void SetCourseTitle(string courseTitle);

    // TODO: Declare accessor functions - GetCourseNumber(), GetCourseTitle()
    string GetCourseNumber();
    string GetCourseTitle();

    // TODO: Declare PrintInfo()
    void PrintInfo();
};

#endif
