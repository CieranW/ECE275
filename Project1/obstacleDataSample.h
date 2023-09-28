#ifndef obstacleDataSample_hpp
#define obstacleDataSample_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

// This enumerated type provides entries for each of the
// potential labels attached to a sample
enum FilterStatus
{
    UNDEFINED = -1,
    VALID,
    FILTERED,
    ANGLE_RESET,
    DISTANCE_RESET
};

// This struct is used to print out the filtered data
// (and can also be used to store data from the read files)
typedef struct obstacleDataSample_struct
{
    double timestamp;
    double distance;
    double angle;
    FilterStatus status;

    // vector<obstacleDataSample> data;
} obstacleDataSample;

string printSample(obstacleDataSample sample);

// add your own functions (if prefer)
int ReadFile(string fileName, vector<obstacleDataSample> &data);
void Classify(vector<obstacleDataSample> &data);
void Filter(vector<obstacleDataSample> &data);

#endif /* obstacleData_hpp */
