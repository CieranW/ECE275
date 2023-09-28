#include "obstacleDataSample.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

int ReadFile(string inputFileName, vector<obstacleDataSample> &data)
{
    ifstream inFile(inputFileName);
    string linetext;
    int count = 0;

    // Check if the file is open
    if (!inFile.is_open())
    {
        cerr << "Could not open the file." << endl;
        return 1;
    }

    // Read each line and extract the data
    while (getline(inFile, linetext))
    {
        // Remove commas from the linetext
        linetext.erase(remove(linetext.begin(), linetext.end(), ','), linetext.end());

        istringstream lineString(linetext);
        obstacleDataSample tempData;

        lineString >> tempData.timestamp;
        lineString >> tempData.distance;
        lineString >> tempData.angle;

        data.push_back(tempData);
        count++;
    }

    inFile.close();
    return count;
}

void Classify(vector<obstacleDataSample> &data)
{
}

void Filter(vector<obstacleDataSample> &data)
{
}