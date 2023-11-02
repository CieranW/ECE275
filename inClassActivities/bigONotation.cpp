#include <iostream>

using namespace std;

// Determining the Big O Notation of the following code snippets
int main()
{
    int n = 10;
    int count = 0;
    int decount = 0;
    int sum = 0;

    // Big O notation of O(n^2)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (numbers[i] < numbers[j])
            {
                count++;
            }
            else
            {
                decount++;
            }
        }
    }

    // Big O notation of O(n^3)
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                sum = sum + aVals[i][k] * bVals[k][j];
            }
            cVals[i][j] = sum;
        }
    }
    return 0;
}