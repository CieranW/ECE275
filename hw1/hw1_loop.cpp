#include <iostream>
using namespace std;

int main()
{
    int userInt, validCount = 0, invalidCount = 0, sum = 0;

    cin >> userInt;
    while (userInt != 0)
    {
        if (userInt > 12 || userInt < 2)
        {
            // Num not valid (out of range)
            invalidCount += 1;
        }
        else
        {
            // Valid and add to sum to calculate avg later
            sum += userInt;
            validCount += 1;
        }
        cin >> userInt;
    }

    if (validCount == 0)
    {
        cout << "Average: 0" << endl;
    }
    else
        cout << "Average: " << (static_cast<float>(sum)) / validCount << endl;
    cout << "Valid: " << validCount << endl;
    cout << "Invalid: " << invalidCount << endl;

    return 0;
}