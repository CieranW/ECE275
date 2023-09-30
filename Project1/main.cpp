#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "obstacleDataSample.h"

using namespace std;

#define PI 3.141592653589793238
#define FILTER_WIDTH 11

///////////////// Before submitting your code
// 1) uncomment this part since zyBooks use it.
int main(int argc, const char *argv[])
{
    if (argc != 3)
    {
        std::cout << "./project1 inputFile outputFile" << std::endl;
        return EXIT_FAILURE;
    }
    string inputFileName = argv[1];
    string outputFileName = argv[2];
    ///////////////////// uncomment above befofre submitting on zyBooks /////////////////
    // 2) Comment the next 3 lines below

    // int main(void)
    // {
    //     string inputFileName = "inputFile9.txt";   // Do NOT change the name "inputFileName" since used above
    //     string outputFileName = "outputFile9.txt"; // Do NOT change the name "outputFileName" since used above

    // Add your code //
    // Variables
    vector<obstacleDataSample> data;

    ReadFile(inputFileName, data);

    // For testing purposes
    // for (size_t i = 0; i < data.size(); i++)
    // {
    //     cout << fixed << setprecision(6);
    //     cout << data[i].timestamp << " " << data[i].distance << " " << data[i].angle << endl;
    // }
    // cout << endl
    //      << endl;

    Classify(data);

    // For testing purposes
    // for (size_t i = 0; i < data.size(); i++)
    // {
    //     cout << fixed << setprecision(6);
    //     cout << data[i].timestamp << " " << data[i].distance << " " << data[i].angle << " " << data[i].status << endl;
    // }

    // cout << endl
    //      << endl;

    // Filters the data and reclassifies it
    Filter(data);

    // Prints the data out to a new file
    ofstream outFile;
    outFile.open(outputFileName);
    outFile << fixed << setprecision(6);
    for (size_t i = 0; i < data.size(); i++)
    {
        obstacleDataSample tempData = data[i];
        string output;
        output = printSample(tempData);

        // Write to file
        outFile << output << endl;

        // For testing purposes
        // cout << output << endl;
    }
    return 0;
}