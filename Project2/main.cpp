#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

// Header files
#include "MathVector.h"
#include "Input.h"
#include "State.h"
#include "Vehicle.h"
using namespace std;

///////////////// Before submitting your code
// 1) uncomment this part since zyBooks use it.
/*int main(int argc, const char* argv[]) {
    if (argc != 3)
    {
        std::cout << "./project2 inputFile outputFile" << std::endl;
        return EXIT_FAILURE;
    }
    string inputFileName = argv[1];
    string outputFileName = argv[2];*/
///////////////////// uncomment above befofre submitting on zyBooks /////////////////
// 2) Comment the next 3 lines below

int main(void)
{
    string inputFileName = "inputFile5.txt";   // Do NOT change the name "inputFileName" since used above
    string outputFileName = "outputFile5.txt"; // Do NOT change the name "outputFileName" since used above

    // Add your code //
    ifstream inputFile(inputFileName);

    if (!inputFile.is_open())
    {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    // Open the output file for writing
    ofstream outputFile(outputFileName);

    if (!outputFile.is_open())
    {
        cerr << "Error: Unable to open the output file." << endl;
        return 1;
    }

    // Declare variables
    string line, initialPosition, variableName;
    double wheelbase, Dt, x, y, delta, theta, v, deltaDot;
    char comma;

    // Set fixed precision
    cout << fixed << setprecision(3);

    // Add these lines to skip the lines with variable names
    for (int i = 0; i < 3; i++)
    {
        getline(inputFile, line);
        istringstream lineStream(line); // Create a stringstream to process the line

        if (i == 0)
        {
            lineStream >> variableName >> wheelbase;
        }
        else if (i == 1)
        {
            lineStream >> variableName >> x >> comma >> y >> comma >> delta >> comma >> theta;
        }
        else if (i == 2)
        {
            lineStream >> variableName >> Dt;
        }
    }

    double DtTemp = 0;
    double DtFixed = Dt;
    // Assign State with the initial position
    State state(x, y, delta, theta);
    // Updates Vehicle with the new state and wheelbase
    Vehicle vehicle(state, wheelbase);

    outputFile << fixed << setprecision(3); // Set the desired format

    while (getline(inputFile, line))
    {
        Input input;
        State *statePtr = vehicle.getState();

        // Call the readElements() function on the Input instance
        if (input.readElements(line))
        {
            // Call the update() function on the Vehicle instance
            statePtr = vehicle.update(&input, DtFixed);

            // Call the toString() function on the State instance
            string stateStr = statePtr->toString();

            // Write the state string to the output file
            outputFile << DtTemp << "," << stateStr << "," << input.getV() << "," << input.getDeltaDot() << endl;

            // Update the time step
            DtTemp += Dt;
        }
        else
        {
            // Line was not successfully processed
            cerr << "Error: Unable to read values." << endl;
        }
    }

    // Close the input/output file
    inputFile.close();
    outputFile.close();

    return 0;
}

// To run the program, type the following in the terminal window:
// g++ -c main.cpp -o main.o && g++ -c MathVector.cpp -o MathVector.o && g++ -c State.cpp -o State.o && g++ -c Vehicle.cpp -o Vehicle.o && g++ -c Input.cpp -o Input.o && g++ main.o MathVector.o State.o Vehicle.o Input.o -o my_program && ./my_program
