#include "OfferedCourse.h"

int main()
{
    Course myCourse;
    OfferedCourse myOfferedCourse;

    string courseNumber, courseTitle;
    string oCourseNumber, oCourseTitle, instructorName, location, classTime;

    getline(cin, courseNumber);
    getline(cin, courseTitle);

    getline(cin, oCourseNumber);
    getline(cin, oCourseTitle);
    getline(cin, instructorName);
    getline(cin, location);
    getline(cin, classTime);

    myCourse.SetCourseNumber(courseNumber);
    myCourse.SetCourseTitle(courseTitle);
    myCourse.PrintInfo();

    myOfferedCourse.SetCourseNumber(oCourseNumber);
    myOfferedCourse.SetCourseTitle(oCourseTitle);
    myOfferedCourse.SetInstructorName(instructorName);
    myOfferedCourse.SetLocation(location);
    myOfferedCourse.SetClassTime(classTime);
    myOfferedCourse.PrintInfo();

    cout << "   Instructor Name: " << myOfferedCourse.GetInstructorName() << endl;
    cout << "   Location: " << myOfferedCourse.GetLocation() << endl;
    cout << "   Class Time: " << myOfferedCourse.GetClassTime() << endl;
}
