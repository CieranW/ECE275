#include "obstacleDataSample.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#define FILTER_WIDTH 11

int ReadFile(string inputFileName, vector<obstacleDataSample> &data)
{
    ifstream inFile(inputFileName);
    string linetext;
    istringstream lineString(linetext);
    obstacleDataSample tempData;

    // Check if the file is open
    if (!inFile.is_open())
    {
        cerr << "Could not open the file." << endl;
        return 1;
    }

    // Read each line and extract the data
    while (!inFile.eof() && inFile.good())
    {
        getline(inFile, linetext);
        lineString.clear();
        lineString.str(linetext);

        string value;

        lineString >> tempData.timestamp;
        if (getline(lineString, value, ','))
        {
            lineString.ignore();
        }
        lineString >> tempData.distance;
        if (getline(lineString, value, ','))
        {
            lineString.ignore();
        }
        lineString >> tempData.angle;

        data.push_back(tempData);
    }

    inFile.close();
    return 0;
}

void Classify(vector<obstacleDataSample> &data)
{
    const double MAX_DIST = 81.0;
    const double ANGLE_DEFAULT = -M_PI / 2.0;

    for (size_t i = 0; i < data.size(); i++)
    {
        // 1st data point of any list is allocated UNDEFINED
        if (i == 0)
        {
            data[i].status = UNDEFINED;
        }
        else
        {
            // If the distance or angle are equal to the max distance or default angle, status is UNDEFINDED
            if (data[i].distance == MAX_DIST || data[i].angle == ANGLE_DEFAULT)
            {
                data[i].status = UNDEFINED;
            }

            // Assigns angleDiff (in degrees) the difference between the current and previous data point, also converts radians into degrees.
            double angleDiff = fabs((data[i].angle - data[i - 1].angle) * (180.0 / M_PI));
            // Checks to see if the angle difference is within tolerance of 15 degrees, status assigned ANGLE_RESET
            if ((angleDiff > 15))
            {
                data[i].status = ANGLE_RESET;
            }

            // Assigns distDiff the difference between current and previous data points
            double distDiff = fabs(data[i].distance - data[i - 1].distance);
            // Checks to see if the distance difference is within tolerance of 0.1 meters, status assigned DISTANCE_RESET
            if ((distDiff > 0.1))
            {
                data[i].status = DISTANCE_RESET;
            }

            // If both the distance and angle differences are within the tolerance limit (0.1 meters and 15 degrees respectively), status is assigned VALID
            if (distDiff < 0.1 && angleDiff < 15)
            {
                data[i].status = VALID;
            }

            // If either the distance or angle difference are greater than the tolerance, and the angle or distance are not the max distance or default angle, status is assigned ANGLE_RESET
            if ((distDiff > 0.1 || angleDiff > 15) && (data[i].angle != ANGLE_DEFAULT || data[i].distance != MAX_DIST))
            {
                data[i].status = ANGLE_RESET;
            }
        }
    }
}

int Filter(vector<obstacleDataSample> &data)
{
    vector<obstacleDataSample> tempData;
    int filterStart, filterEnd;

    for (size_t i = 0; i < data.size(); i++)
    {
        // Checks to see if the data has been classified as valid and pushes it to tempData for filtering
        if (data[i].status == 0)
        {
            tempData.push_back(data[i]);
        }
    }

    // If the dataset is smaller than the filter width, stop and return the original dataset, unfiltered
    if (tempData.size() < FILTER_WIDTH)
    {
        return 1;
    }

    else
    {
        filterStart = FILTER_WIDTH / 2;
        filterEnd = tempData.size() - filterStart;

        int size = tempData.size();
        double sum = 0.0;
        for (int i = 0; i < size; ++i)
        {
            // Filters the data by the elements within the desired range so that there are no errors/unaccessible data points
            if (i >= filterStart && i < filterEnd)
            {
                sum = 0.0;
                // At a certain element position, accesses all the data points within the filter width to add towards the sum for avg calc
                for (int j = (i - filterStart); j <= (i + filterStart); j++)
                {
                    sum += tempData[j].distance;
                }
                tempData[i].distance = sum / FILTER_WIDTH;
                tempData[i].status = FILTERED;
            }
            else
            {
                tempData[i].distance = tempData[i].distance;
            }
        }

        // Reassigns the filtered data to the original dataset
        for (size_t i = 0; i < data.size(); ++i)
        {
            for (size_t j = 0; j < tempData.size(); ++j)
            {
                if ((data[i].timestamp == tempData[j].timestamp) && (data[i].status == 0))
                {
                    data[i].distance = tempData[j].distance;
                    data[i].status = tempData[j].status;
                    break;
                }
            }
        }
    }

    return 0;
}

string printSample(obstacleDataSample sample)
{
    // Accesses the status in each data point and characterizes it into a string
    string status, fullLine;
    switch (sample.status)
    {
    case -1:
        status = "UNDEFINED";
        break;
    case 0:
        status = "VALID";
        break;
    case 1:
        status = "FILTERED";
        break;
    case 2:
        status = "ANGLE_RESET";
        break;
    case 3:
        status = "DISTANCE_RESET";
        break;
    }
    // Combines all the information in a data point into one line, outputting with commas
    fullLine = to_string(sample.timestamp) + ", " + to_string(sample.distance) + ", " + to_string(sample.angle) + ", " + status;
    return fullLine;
}