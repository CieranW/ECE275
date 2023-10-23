# Project 2 Requirements Summary

Create a program that will simulate the behavior of a car, based on input files that describe its behavior. The input file will include the initial position and orientation of a vehicle, and a set of commands to make it move. The output of the program should be a time-series that describes the position and orientation of the vehicle, and records the command given at each time as well..

### Data description and motivation

The data in the input file first describes characteristics of the vehicle (wheelbase) and its initial state. Then, the file contains an array of input values that describe the velocity and steering angle rate of change for the vehicle.

The goal of the project is to simulate a car-like robot's motion. A simple algorithm is applied to simulate the state evolution of the vehicle, based on kinematic motion.

Note: this project is developed by Dr. Jonathan Sprinkle

### Classes

Your project must use at least the below classes, for which required features are included in their template definitions.

-   MathVector
-   Input (note: inherits from MathVector)
-   State: (note: inherits from MathVector)
-   Vehicle
(You may add Project2.h and Project2.cpp if you prefer. If you do not use them, submit the blank files.)

The following details are valid for your implementations:

-   You are free to provide inline implementations if you choose
-   You are free to add more features to prototyped classes
-   You are free to edit header files to include other headers commonly available for C++ (or to change the way in which your headers are included)
-   You are free to define other classes; if you do, you should define them in the Project2 header file, and ensure their implementations are in the Project2 cpp file.
Additional descriptions for the required classes are below:

### MathVector

This class should abstract a one dimensional math vector of double values, with the number of elements of the vector set on construction. It should provide a constructor that permits creating the vector from a string of comma separated numerical values. It should also provide a function to print those values (again, with comma separation) with fixed precision 3.

When reading in values into the vector, the return value should be true only if all values are successfully read in. See explanations how to implement each function in MathVector.cpp. `

### Input

This class should inherit with public access to the MathVector class. It should provide methods to get and set values of v (input velocity) and deltaDot. Required method signatures are included in the prototype header and function definitions are already given in its cpp file. Other methods or features may be added at your discretion.

### State

This class should inherit with public access to the MathVector class. It should provide methods to get and set values of x, y, delta, and theta. Required method signatures are included in the prototype header provided, and other methods or features may be added at your discretion. See explanations how to implement each function in State.cpp.

### Vehicle

This class simulates the behavior of a car-like robot. The Vehicle should maintain its own State, and when the update(.) function is called it returns a pointer to its state. It is the responsibility of the calling function to make a copy, if one is needed, of the State return value. When deleted, the Vehicle should ensure that any allocated memory is destroyed. See explanations how to implement each function in Vehicle.cpp.

The equations of motion for the car-like robot are below:

x1(t+Dt) = x1(t) + Dt u1(t) cos(x3(t)) cos(x4(t))
x2(t+Dt) = x2(t) + Dt u1(t) cos(x3(t)) sin(x4(t))
x3(t+Dt) = x3(t) + Dt u2(t)
x4(t+Dt) = x4(t) + Dt u1(t) (1/L) sin(x3(t))
Where x1 is x position, x2 is y position, x3 is tire angle delta (in radians) and x4 is heading theta (in radians). L is the Vehicle's wheelbase. The variable u1 is the input velocity (v), and u2 is the tire angle rate of change (deltaDot).

For the entire simulation, assume a constant value of Delta t (Dt) as set in the inputFile parameters. The value for x3 (tire angle) must always be between [-0.5236,0.5236] radians. If a value is commanded outside this range, then x3 will be saturated using the above range. Likewise, heading should always be between [0, 2π)---it is up to you to determine how to wrap values of heading. Defined values are present for these ranges inside of State.h

### Input File

An example input file is included below:

Wheelbase: 2.6
InitialPose: 1.0,0,0,0
Dt: 0.100
1.000, 0.000
1.000, 0.000
1.000, 0.000
1.000, 0.000
1.000, 0.000
The format is given below, with variable types substituting for values. The Wheelbase, Initial Pose, and Dt are provided in this order, and must be read in prior to reading the Input vectors.

Wheelbase: double
InitialPose: double,double,double,double
Dt: double
double,double
double,double
...
These correspond to:

L (wheelbase in the Vehicle)
State0 (the initial state of the Vehicle)
Dt (the timestamp to use in the simulation)
1 or more lines of Inputs
...

### Output File

The output file format should be of comma separated values with precision 3. The values for each timestep (in order) are: t, x, y, theta, delta, v, deltadot. In short, there are

time, state, input
time, state, input
time, state, input
time, state, input
...
time, state, input
time, state
For the last line, only state and time will be available. NO additional commas or zeros should be added for the final inputs (i.e., the state at time k+Dt is a function of x(k) and u(k), so there is no k+Dt input unless provided). An example output is given below:

0.000,1.000,0.000,0.000,0.000,1.000,0.000
0.100,1.100,0.000,0.000,0.000,1.000,0.000
0.200,1.200,0.000,0.000,0.000,1.000,0.000
0.300,1.300,0.000,0.000,0.000,1.000,0.000
0.400,1.400,0.000,0.000,0.000,1.000,0.000
0.500,1.500,0.000,0.000,0.000