#include <iostream>
#include "Student.h"
using namespace std;
int main()
{
    Student student1 = Student();
    cout << student1.GetFirst() << " "
         << student1.GetLast() << "/"
         << student1.GetGPA() << endl;
    Student student2 = Student("Wilma", "Cheers", 3.75);
    cout << student2.GetFirst() << " "
         << student2.GetLast() << "/"
         << student2.GetGPA() << endl;
    return 0;
}
