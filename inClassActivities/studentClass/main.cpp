#include <iostream>
#include "Student.h"
using namespace std;
int main()
{
    Student student1 = Student();
    cout << student1.GetFirstName() << " "
         << student1.GetLastName() << "/"
         << student1.GetGPA() << endl;
    Student student2 = Student("Wilma", "Cheers", 3.75);
    cout << student2.GetFirstName() << " "
         << student2.GetLastName() << "/"
         << student2.GetGPA() << endl;
    return 0;
}
