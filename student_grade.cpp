#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

typedef struct student_struct
{
    string firstName, lastName;
    vector<int> exam;
    char finalGrade;

    // Constructor to initialize the exam vector with zeros
    student_struct() : exam(3, 0) {}
} student;

void initialize_Class(vector<student> &Class);

int main()
{
    vector<student> Class(5);
    initialize_Class(Class);
    double studentAvg, mid1Sum = 0.0, mid2Sum = 0.0, finalSum = 0.0;

    for (unsigned int i = 0; i < Class.size(); i++)
    {
        studentAvg = 0;
        studentAvg = (Class.at(i).exam.at(0) + Class.at(i).exam.at(1) + Class.at(i).exam.at(2)) / 3.0;

        if (studentAvg >= 90.0)
            Class.at(i).finalGrade = 'A';
        else if (studentAvg >= 80)
            Class.at(i).finalGrade = 'B';
        else if (studentAvg >= 70)
            Class.at(i).finalGrade = 'C';
        else if (studentAvg >= 60)
            Class.at(i).finalGrade = 'D';
        else
            Class.at(i).finalGrade = 'F';

        mid1Sum += Class.at(i).exam.at(0);
        mid2Sum += Class.at(i).exam.at(1);
        finalSum += Class.at(i).exam.at(2);
    }

    for (unsigned int i = 0; i < Class.size(); i++)
    {
        cout << Class.at(i).firstName << " ";
        cout << Class.at(i).lastName << " ";
        cout << Class.at(i).exam.at(0) << " ";
        cout << Class.at(i).exam.at(1) << " ";
        cout << Class.at(i).exam.at(2) << " ";
        cout << Class.at(i).finalGrade << endl;
    }

    cout << fixed << setprecision(2);
    cout << "Averages: " << endl
         << "Midterm 1: " << mid1Sum / Class.size() << endl;
    cout << "Midterm 2: " << mid2Sum / Class.size() << endl;
    cout << "Final: " << finalSum / Class.size() << endl;

    return 0;
}

// void initialize_Class(vector<student> &Class)
// {
//     Class.at(0).firstName = "Barrett";
//     Class.at(0).lastName = "Edan";
//     // Class.at(0).exam = {70, 45, 59};
//     Class.at(0).exam.at(0) = 70;
//     Class.at(0).exam.at(1) = 45;
//     Class.at(0).exam.at(2) = 59;

//     Class.at(1).firstName = "Bradshaw";
//     Class.at(1).lastName = "Reagan";
//     // Class.at(1).exam = {96, 97, 88};
//     Class.at(1).exam.at(0) = 96;
//     Class.at(1).exam.at(1) = 97;
//     Class.at(1).exam.at(2) = 88;

//     Class.at(2).firstName = "Charlton";
//     Class.at(2).lastName = "Caius";
//     // Class.at(2).exam = {73, 94, 80};
//     Class.at(2).exam.at(0) = 73;
//     Class.at(2).exam.at(1) = 94;
//     Class.at(2).exam.at(2) = 80;

//     Class.at(3).firstName = "Mayo";
//     Class.at(3).lastName = "Tyrese";
//     // Class.at(3).exam = {88, 61, 36};
//     Class.at(3).exam.at(0) = 88;
//     Class.at(3).exam.at(1) = 61;
//     Class.at(3).exam.at(2) = 36;

//     Class.at(4).firstName = "Stern";
//     Class.at(4).lastName = "Brenda";
//     // Class.at(4).exam = {90, 86, 45};
//     Class.at(4).exam.at(0) = 90;
//     Class.at(4).exam.at(1) = 86;
//     Class.at(4).exam.at(2) = 45;
// }