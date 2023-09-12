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

int main()
{
    ifstream inSS;
    ofstream outSS;

    inSS.open("Student_grades.txt");
    if (!inSS.is_open())
    {
        cout << " file not found\n";
        return 1;
    }
    // Variables
    vector<student> Class;
    student tempStudent;
    double studentAvg, mid1Sum = 0.0, mid2Sum = 0.0, finalSum = 0.0;
    string linetext;
    istringstream lineString;

    while (!inSS.eof() && inSS.good())
    {
        getline(inSS, linetext);
        lineString.clear();
        lineString.str(linetext);

        lineString >> tempStudent.firstName;
        lineString >> tempStudent.lastName;
        lineString >> tempStudent.exam.at(0);
        lineString >> tempStudent.exam.at(1);
        lineString >> tempStudent.exam.at(2);

        Class.push_back(tempStudent);
    }
    inSS.close();

    ofstream outputFile("studentGradeReport.txt");

    for (unsigned int i = 0; i < Class.size(); i++)
    {
        studentAvg = 0.0;
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
        outputFile << Class.at(i).firstName << " ";
        outputFile << Class.at(i).lastName << " ";
        outputFile << Class.at(i).exam.at(0) << " ";
        outputFile << Class.at(i).exam.at(1) << " ";
        outputFile << Class.at(i).exam.at(2) << " ";
        outputFile << Class.at(i).finalGrade << endl;
    }

    outputFile << fixed << setprecision(2);
    outputFile << "\nAverages: \n"
               << "Midterm 1: " << mid1Sum / Class.size() << endl;
    outputFile << "Midterm 2: " << mid2Sum / Class.size() << endl;
    outputFile << "Final: " << finalSum / Class.size() << endl;

    outputFile.close();
    return 0;
}
