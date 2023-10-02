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

    // Check if the file is open
    if (!inFile.is_open())
    {
        cerr << "Could not open the file." << endl;
        return 1;
    }

    string linetext;
    string value;
    obstacleDataSample tempData;

    // Read each line and extract the data
    while (getline(inFile, linetext))
    {
        istringstream lineString(linetext);

        lineString >> tempData.timestamp;
        getline(lineString, value, ',');
        lineString >> tempData.distance;
        getline(lineString, value, ',');
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
            // Assigns distDiff the difference between current and previous data points
            double distDiff = fabs(data[i].distance - data[i - 1].distance);

            // Checks to see if the angle difference is within tolerance of 15 degrees, status assigned ANGLE_RESET
            if ((angleDiff > 15))
            {
                data[i].status = ANGLE_RESET;
            }

            // Checks to see if the distance difference is within tolerance of 0.1 meters, status assigned DISTANCE_RESET
            else if ((distDiff > 0.1) && (angleDiff < 15))
            {
                data[i].status = DISTANCE_RESET;
            }

            // If either the distance or angle difference are greater than the tolerance, and the angle or distance are not the max distance or default angle, status is assigned ANGLE_RESET
            else if ((distDiff > 0.1 || angleDiff > 15) && (data[i].angle != ANGLE_DEFAULT || data[i].distance != MAX_DIST))
            {
                data[i].status = ANGLE_RESET;
            }

            // If both the distance and angle differences are within the tolerance limit (0.1 meters and 15 degrees respectively), status is assigned VALID
            if (distDiff < 0.1 && angleDiff < 15)
            {
                data[i].status = VALID;
            }
        }
    }
}

int Filter(vector<obstacleDataSample> &data)
{
    int filterStart, filterEnd;
    int size = data.size();
    vector<obstacleDataSample> filteredData;
    obstacleDataSample tempDataSample;

    filterStart = FILTER_WIDTH / 2;
    filterEnd = size - filterStart;

    // Creates a copy of the data vector to be used for the filtered data
    for (int i = 0; i < size; i++)
    {
        filteredData.push_back(data[i]);
    }

    // If the dataset window from that datapoint is smaller than the filter width, stop and return the original datapoint, unfiltered
    for (int i = 0; i < size; i++)
    {
        bool filterIsValid = true;

        if (data[i].status == VALID)
        {
            // Filters the data by the elements within the desired range so that there are no errors/unaccessible data points
            for (int j = (i - filterStart); j <= (i + filterStart); j++)
            {
                if (data[j].status != 0)
                {
                    // If the data point is not VALID, the filter is not valid
                    filterIsValid = false;
                }
            }

            // If the filter is valid, perform the filter calculations
            if ((filterIsValid == true) && (i < filterEnd))
            {
                double sum = 0.0;

                // At a certain element position, accesses all the data points within the filter width to add towards the sum for avg calc
                for (int j = (i - filterStart); j <= (i + filterStart); j++)
                {
                    sum += data[j].distance;
                }
                // Assigns the filtered data to the filteredData vector and updates the status to FILTERED
                filteredData[i].distance = sum / FILTER_WIDTH;
                filteredData[i].status = FILTERED;
                // Assigning the filtered data to a second vector will allow the data in the original vector to remain unchanged until the end of the function, resulting in the calculations being performed on the original data thus not affecting it in any way, shape, or form till the very end of the function
            }
            // If the data point is not within the filter range, the distance is kept the same and the status is kept VALID
            else
            {
                data[i].distance = data[i].distance;
            }
        }
    }

    // Reassigns the filtered data to the original data vector
    for (int i = 0; i < size; i++)
    {
        data[i] = filteredData[i];
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
        status = "ANGLE RESET";
        break;
    case 3:
        status = "DISTANCE RESET";
        break;
    }
    // Combines all the information in a data point into one line, outputting with commas
    fullLine = to_string(sample.timestamp) + "," + to_string(sample.distance) + "," + to_string(sample.angle) + "," + status;
    return fullLine;
}