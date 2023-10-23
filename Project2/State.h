//
//  State.h
//

#ifndef State_h
#define State_h

#include <stdio.h>
#include "MathVector.h"

#include <math.h>
#define DELTA_MAX 0.5236
#define DELTA_MIN (-DELTA_MAX)
#define HEADING_MAX (2*M_PI)

class State : public MathVector {
public:
    State( );
    State( double x, double y, double delta, double theta );
    ~State( ) { }
    State( const State& other );
    double getX( );
    double getY( );
    double getDelta( );
    double getTheta( );
    void setX( double newX );
    void setY( double newY );
    void setDelta( double newDelta );
    void setTheta( double newTheta );
};

#endif /* State_h */
