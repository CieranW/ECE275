#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    vector<int> intVect;
    int value, i, max = -10000000000000, sum = 0;
    double avg;

    // Loop to keep adding values to the vector till the break condition is met
    while (1)
    {
        cin >> value;

        if (value == 0)
            break;
        else
        {
            intVect.push_back(value);
        }
    }

    // Loop to print and add to sum for avg calc
    for (i = 0; i < intVect.size(); i++)
    {
        // Finds max value
        if (intVect.at(i) > max)
            max = intVect.at(i);
        // Keeps adding to the sum and prints out
        sum += intVect.at(i);
        cout << intVect.at(i);
        // Prints out commas unless the last value in the vector
        if (i != intVect.size() - 1)
            cout << ", ";
        else
            cout << endl;
    }
    // Calculate average
    avg = sum / intVect.size();

    cout << "Max is " << max << endl;
    cout << "Average is " << avg << endl;

    return 0;
}