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
/*int main(int argc, const char* argv[]) {
    if (argc != 3)
    {
        std::cout << "./project1 inputFile outputFile" << std::endl;
        return EXIT_FAILURE;
    }
    string inputFileName = argv[1];
    string outputFileName = argv[2];*/
///////////////////// uncomment above befofre submitting on zyBooks /////////////////
// 2) Comment the next 3 lines below

int main(void)
{
    string inputFileName = "inputFile9.txt";   // Do NOT change the name "inputFileName" since used above
    string outputFileName = "outputFile9.txt"; // Do NOT change the name "outputFileName" since used above

    // Add your code //
    // Variables
    vector<obstacleDataSample> data;
    int fileSize;
    // Open file
    ifstream inSS;
    ofstream outSS;

    fileSize = ReadFile(inputFileName, data);
    for (size_t i = 0; i < data.size(); i++)
    {
        cout << data[i].timestamp << " " << data[i].distance << " " << data[i].angle << endl;
    }
    return 0;
}