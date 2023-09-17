#include <iostream>
#include <vector>
using namespace std;

void ExactChange(int userTotal, vector<int> &coinVals)
{
    int temp;
    coinVals.at(3) = userTotal / 25;
    temp = userTotal % 25;
    coinVals.at(2) = temp / 10;
    temp = temp % 10;
    coinVals.at(1) = temp / 5;
    coinVals.at(0) = temp % 5;
}

int main()
{
    int inputVal;
    vector<int> changeAmount(4); // p, n, d, q

    cin >> inputVal;

    ExactChange(inputVal, changeAmount);

    if (inputVal == 0)
    {
        cout << "No change\n";
    }
    else
    {
        if (changeAmount.at(3) > 0)
            cout << changeAmount.at(3) << " quarters\n";
        if (changeAmount.at(2) > 0)
            cout << changeAmount.at(2) << " dimes\n";
        if (changeAmount.at(1) > 0)
            cout << changeAmount.at(1) << " nickels\n";
        if (changeAmount.at(0) > 0)
            cout << changeAmount.at(0) << " pennies\n";
    }

    return 0;
}