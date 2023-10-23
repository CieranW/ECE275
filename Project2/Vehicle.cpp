#include "Vehicle.h"

#include <vector>

//already implemented - you can use it as it is
Vehicle::Vehicle()
    : state(NULL)
{
    this->state = new State(0.0, 0.0, 0.0, 0.0);
}

//already implemented - you can use it as it is
Vehicle::Vehicle(State s, double wheelbase)
    : wheelbase(wheelbase)
{
    this->state = new State(s);
}

//already implemented - you can use it as it is
Vehicle::~Vehicle()
{
    if (state) {
        delete state;
    }
}

//already implemented - you can use it as it is
State* Vehicle::getState()
{
    return this->state;
}


// return the wheelbase value
//double getWheelbase();


// returns a pointer to the current state. The calling object should make
// a deep copy of the data if it wants to keep it
//State* update(Input* u, double ts = 0.1);
    // update the state value and return its pointer
    // state has x, y, delta and theta
    // u has v and DeltaDot
//x1(t + Dt) = x1(t) + Dt u1(t) cos(x3(t)) cos(x4(t))
//x2(t + Dt) = x2(t) + Dt u1(t) cos(x3(t)) sin(x4(t))
//x3(t + Dt) = x3(t) + Dt u2(t)
//x4(t + Dt) = x4(t) + Dt u1(t) (1 / L) sin(x3(t))

//where x1 is x position, x2 is y position, 
//x3 is tire angle delta(in radians) and x4 is heading theta(in radians).
//L is the Vehicle's wheelbase. 
//The variable u1 is the input velocity (v), and u2 is the tire angle rate of change (deltaDot).

// returns a pointer to the current state. The calling object should make
// a deep copy of the data if it wants to keep it

