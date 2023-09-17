#include <iostream>
#include <vector>
using namespace std;

int GetMaxInt(vector<int> listInts);

int main()
{
    vector<int> listInts;
    int userInt, numCount;

    // Get num of ints that will go into the list
    cin >> numCount;

    // Adds each value inputted by the user into the list
    for (int i = 0; i < numCount; i++)
    {
        cin >> userInt;
        listInts.push_back(userInt);
    }

    // Calls the GetMaxInt function and assigns it to a variable so it's fixed and doesn't change in the for loop
    int maxInt = GetMaxInt(listInts);

    // Adjusts each value in the original list by subtracting the values from the max int, prints out each value with a space after
    for (unsigned int i = 0; i < listInts.size(); i++)
    {
        listInts[i] = maxInt - listInts[i];
        cout << listInts.at(i) << " ";
    }
    cout << endl;

    return 0;
}

// Function to find max value in a list, returns the max value
int GetMaxInt(vector<int> listInts)
{
    int maxInt = 0;

    for (unsigned int i = 0; i < listInts.size(); i++)
    {
        if (listInts[i] > maxInt)
            maxInt = listInts[i];
    }

    return maxInt;
}