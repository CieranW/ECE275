#ifndef CATH
#define CATH

#include <string>
#include "Pet.h"

class Cat : public Pet
{
private:
    string catBreed;

public:
    void SetBreed(string userBreed);

    string GetBreed();
};

#endif