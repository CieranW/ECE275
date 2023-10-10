#include "Plant.h"
#include "Flower.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// TODO: Define a PrintVector function that prints an vector of plant (or flower) object pointers

int main()
{
    // TODO: Declare a vector called myGarden that can hold object of type plant pointer

    // TODO: Declare variables - plantName, plantCost, flowerName, flowerCost,
    //       colorOfFlowers, isAnnual
    string input;

    cin >> input;

    while (input != "-1")
    {
        // TODO: Check if input is a plant or flower
        //       Store as a plant object or flower object
        //       Add to the vector myGarden
        cin >> input;
    }

    // TODO: Call the method PrintVector to print myGarden

    for (size_t i = 0; i < myGarden.size(); ++i)
    {
        delete myGarden.at(i);
    }

    return 0;
}