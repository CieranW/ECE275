//
//  Input.cpp
//  sprinkjm_project2
//
//  Created by Jonathan Sprinkle on 9/25/19.
//  Copyright © 2019 Jonathan Sprinkle. All rights reserved.
//

#include "Input.h"

Input::Input()
    : MathVector(2)
{

}

Input::Input(double v, double deltaDot)
    : MathVector(2)
{
    this->elements.at(0) = v;
    this->elements.at(1) = deltaDot;
}

Input::Input(const Input& other)
    : MathVector(other)
{

}

double Input::getDeltaDot() { return elements.at(1); }

double Input::getV() { return elements.at(0); }
