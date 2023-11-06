#include "MathVector.h"
#include "Input.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

// default contructor
// MathVector();   //set numElements to 0, then resize the vector "elements" with numElements
MathVector::MathVector()
{
    numElements = 0;
    elements.resize(numElements);
}

// parameterized contructor
// MathVector(int num_entered); //set numElements to num_entered, then resize the vector "elements" with numElements
MathVector::MathVector(int num_entered)
{
    numElements = num_entered;
    elements.resize(numElements);
}

//~MathVector() { }  //no code needed inside this destructor
MathVector::~MathVector()
{
}

// Given a string consisting of xx, xx, xx (each value seperated by comma)
// extract each value to populate the elements vector
// return true if a string is valid, false if invalid.
// bool readElements(string str);
// bool MathVector::readElements(string str)
// {
//     // Split the input string using a comma as a delimiter
//     vector<string> tokens;
//     stringstream tokenStream(str);
//     string token;
//     while (getline(tokenStream, token, ','))
//     {
//         tokens.push_back(token);
//     }

//     for (const string &token : tokens)
//     {
//         try
//         {
//             // Attempt to convert each token to a double
//             double value = stod(token);

//             // Add the double value to the elements vector
//             elements.push_back(value);
//         }
//         catch (const invalid_argument &e)
//         {
//             cerr << "Invalid argument: " << e.what() << endl;
//             return false; // Return false for invalid input
//         }
//     }

//     return true;
// }

bool MathVector::readElements(string str)
{
    double v, deltaDot;
    char comma;

    istringstream iss(str);

    try
    {
        iss >> v >> comma >> deltaDot;
        elements.at(0) = v;
        elements.at(1) = deltaDot;
    }
    catch (const invalid_argument &e)
    {
        cerr << "Invalid argument: " << e.what() << endl;
        return false; // Return false for invalid input
    }

    return true;
}

// to output a string using data in elements vector.
// string is in the format aa, bb, cc, ... , ss
// For examples, given the vector elements of 0.1 0.2 0.3 0.5
// this funciton returns a string 0.100,0.200,0.300,0.500
// DO NOT add a new line at the end.
// string toString();
string MathVector::toString()
{
    ostringstream oss;
    oss << fixed << setprecision(3); // Set the desired format

    int size = elements.size();
    for (int i = 0; i < size; i++)
    {
        oss << elements.at(i);
        if (i != size - 1)
        {
            oss << ",";
        }
    }

    return oss.str(); // Get the string from the stringstream
}