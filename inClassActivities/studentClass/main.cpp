#include <iostream>
#include <iomanip>
#include <string>
#include "course.h"
using namespace std;
int main()
{
    Course mycourse;
    int beginCount;
    string toDrop;
    // Example students for testing
    mycourse.AddStudent(Student("Henry", "Nguyen", 3.5));
    mycourse.AddStudent(Student("Brenda", "Stern", 2.0));
    mycourse.AddStudent(Student("Lynda", "Robison", 3.2));
    mycourse.AddStudent(Student("Sonya", "King", 3.9));

    beginCount = mycourse.CountStudents();
    cout << "Course size: " << beginCount << " students" << endl;
    mycourse.PrintCourse();
    toDrop = "Stern";
    // toDrop = "Nguyen";
    // toDrop = "Robison";
    // toDrop = "King";
    mycourse.DropStudent(toDrop);
    cout << endl
         << endl
         << "Course size after drop: ";
    cout << mycourse.CountStudents() << " students" << endl;
    mycourse.PrintCourse();
    return 0;
}
