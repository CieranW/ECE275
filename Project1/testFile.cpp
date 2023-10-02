#include "obstacleDataSample.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

int main()
{
    string inputFile1 = "outputFile6.txt";
    string inputFile2 = "outputFile7.txt";

    vector<obstacleDataSample> data1;
    vector<obstacleDataSample> data2;

    ReadFile(inputFile1, data1);
    ReadFile(inputFile2, data2);

    for (size_t i = 0; i < data1.size(); i++)
    {
        if (data1[i].status != data2[i].status && data1[i].timestamp != data2[i].timestamp && data1[i].distance != data2[i].distance && data1[i].angle != data2[i].angle)
        {
            cout << "Error at index " << i << endl;
            cout << "data1: " << printSample(data1[i]) << endl;
            cout << "data2: " << printSample(data2[i]) << endl;
        }
        cout << endl;
    }

    return 0;
}