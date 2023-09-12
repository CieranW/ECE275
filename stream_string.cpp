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
    cout << month << ", " << day << endl;

    return 0;
}