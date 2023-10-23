#include "State.h"


//State();  //see input.cpp to implement this one BUT with number of elements = 4
//since a state is a 1-D array with 4 values: x, y, delta, theta


//State(double x, double y, double delta, double theta); //implement it the same way as State() above

//~State() { }  //no code needed for this one

//below is already implemented - you can use as it is
State::State(const State& other)
    : MathVector(other)
{

}

//return a value at index 0 of elements
//double getX();

//return a value at index 1 of elements
//double getY();

//return a value at index 2 of elements
//double getDelta();

//return a value at index 3 of elements
//double getTheta();

//use newX to set index 0 of elements
//void setX(double newX);

//use newY to set index 1 of elements
//void setY(double newY);


//if newDelta is between [-0.5236,0.5236], use newDelta to set index 2 of elements
//if newDelta < -0.5236,  set index 2 of elements to -0.5236
//if newDelta > 0.5236,  set index 2 of elements to 0.5236
//void setDelta(double newDelta);


//write the code to make sure that newTheta is between [0, 2π)
//then use it to set index 3 of elements
//void setTheta(double newTheta);