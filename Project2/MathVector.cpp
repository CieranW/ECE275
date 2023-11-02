#include "MathVector.h"

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
bool MathVector::readElements(string str)
{
}

// to output a string using data in elements vector.
// string is in the format aa, bb, cc, ... , ss
// For examples, given the vector elements of 0.1 0.2 0.3 0.5
// this funciton returns a string 0.100,0.200,0.300,0.500
// DO NOT add a new line at the end.
// string toString();
string MathVector::toString()
{
}