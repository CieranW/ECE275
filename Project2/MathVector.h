//
//  MathVector.h
//

#ifndef MathVector_h
#define MathVector_h

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class MathVector {
public:
    //default contructor
    MathVector();
    MathVector( int numElements );
    ~MathVector( ) { }
    bool readElements(string str );
    
    std::string toString( );

protected: //to be used with inhetied classes
    int numElements;
    vector<double> elements;
};

#endif /* MathVector_h */