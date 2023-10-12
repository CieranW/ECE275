#include "OfferedCourse.h"

// TODO: Define mutator functions - SetInstructorName(), SetLocation(), SetClassTime()
void OfferedCourse::SetInstructorName(string instructorName)
{
    this->instructorName = instructorName;
}

void OfferedCourse::SetLocation(string location)
{
    this->location = location;
}

void OfferedCourse::SetClassTime(string classTime)
{
    this->classTime = classTime;
}

// TODO: Define accessor functions - GetInstructorName(), GetLocation(), GetClassTime()
string OfferedCourse::GetInstructorName()
{
    return instructorName;
}

string OfferedCourse::GetLocation()
{
    return location;
}

string OfferedCourse::GetClassTime()
{
    return classTime;
}