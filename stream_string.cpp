#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string input = "January 23, 1955";

    istringstream instr(input);

    string month, temp;
    int day, year;

    instr >> month >> day >> year;
    cout << month << ", " << day << ", " << year << endl;

    string input2 = "(520)234-5678";
    int num1, num2, num3;
    char temp1;
    istringstream inSS(input2);

    cout << inSS.str() << endl;
    inSS >> temp1 >> num1 >> temp1 >> num2 >> temp1 >> num3;

    cout << num1 << " " << num2 << " " << num3 << endl;
    return 0;
}