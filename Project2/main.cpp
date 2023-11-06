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
    string inputFileName = "inputFile8.txt";   // Do NOT change the name "inputFileName" since used above
    string outputFileName = "outputFile8.txt"; // Do NOT change the name "outputFileName" since used above

    // Add your code //
    ifstream inputFile(inputFileName);

    if (!inputFile.is_open())
    {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    // Declare variables
    string line, initialPosition, variableName;
    double wheelbase, Dt, x, y, delta, theta, v, deltaDot;

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
            lineStream >> variableName >> x >> y >> delta >> theta;
        }
        else if (i == 2)
        {
            lineStream >> variableName >> Dt;
        }
    }

    double DtTemp = Dt;
    // Assign State with the initial position
    State state(x, y, delta, theta);
    // Updates Vehicle with the new state and wheelbase
    Vehicle vehicle(state, wheelbase);

    // cout << "Wheelbase: " << wheelbase << endl;
    // cout << "Initial Position: " << x << ", " << y << ", " << delta << ", " << theta << endl;
    // cout << "Dt: " << Dt << endl;

    vector<State> states;      // Create a vector to store the State objects
    vector<double> velocities; // Create a vector to store v values
    vector<double> deltaDots;  // Create a vector to store deltaDot values

    while (getline(inputFile, line))
    {
        Input input;

        // Call the readElements() function on the Input instance
        if (input.readElements(line))
        {
            // Line was successfully processed
            // cout << "Values successfully read: " << input.toString() << endl;

            // Call the update() function on the Vehicle instance
            State *newState = vehicle.update(&input, Dt);
            states.push_back(*newState);              // Store the State in the vector
            velocities.push_back(input.getV());       // Store v in the velocities vector
            deltaDots.push_back(input.getDeltaDot()); // Store deltaDot in the deltaDots vector

            // Update Dt
            Dt += DtTemp;
        }
        else
        {
            // Line was not successfully processed
            cerr << "Error: Unable to read values." << endl;
        }
    }

    int size = states.size();
    // // Reset Dt to the original value
    // Dt = DtTemp;

    // // Establish the initial position
    // cout << "Initial Position: " << Dt - Dt << "," << x << "," << y << "," << delta << "," << theta << "," << velocities[0] << "," << deltaDots[0] << endl;

    // for (int i = 0; i < size; i++)
    // {
    //     if (i == (size - 1))
    //     {
    //         cout << "Final Position: " << Dt << "," << states.at(i).toString() << endl;
    //     }
    //     else
    //     {
    //         cout << "Position: " << Dt << "," << states.at(i).toString() << "," << velocities.at(i) << "," << deltaDots.at(i) << endl;
    //     }

    //     // Update Dt
    //     Dt += DtTemp;
    // }
    inputFile.close();

    // Open the output file for writing
    ofstream outputFile(outputFileName);

    if (!outputFile.is_open())
    {
        cerr << "Error: Unable to open the output file." << endl;
        return 1;
    }

    // Write the results to the output file
    // Reset Dt to the original value
    Dt = DtTemp;

    // Fix precision
    outputFile << fixed << setprecision(3);

    // Establish the initial position
    outputFile << Dt - Dt << "," << x << "," << y << "," << delta << "," << theta << "," << velocities[0] << "," << deltaDots[0] << endl;
    for (int i = 0; i < size; i++)
    {
        if (i == (size - 1))
        {
            outputFile << Dt << "," << states.at(i).toString() << endl;
        }
        else
        {
            outputFile << Dt << "," << states.at(i).toString() << "," << velocities.at(i) << "," << deltaDots.at(i) << endl;
        }

        // Update Dt
        Dt += DtTemp;
    }

    // Close the output file
    outputFile.close();

    return 0;
}

// To run the program, type the following in the terminal window:
// g++ -c main.cpp -o main.o && g++ -c MathVector.cpp -o MathVector.o && g++ -c State.cpp -o State.o && g++ -c Vehicle.cpp -o Vehicle.o && g++ -c Input.cpp -o Input.o && g++ main.o MathVector.o State.o Vehicle.o Input.o -o my_program && ./my_program
