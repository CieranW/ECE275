#include "StringInstrument.h"

// TODO: Define mutator functions - SetNumOfStrings(), SetNumOfFrets(), SetIsBowed()
void StringInstrument::SetNumOfStrings(int userNumStrings)
{
    numStrings = userNumStrings;
}
void StringInstrument::SetNumOfFrets(int userNumFrets)
{
    numFrets = userNumFrets;
}
void StringInstrument::SetIsBowed(bool userIsBowed)
{
    isBowed = userIsBowed;
}
// TODO: Define accessor functions - GetNumOfStrings(), GetNumOfFrets(), GetIsBowed()
int StringInstrument::GetNumOfStrings()
{
    return numStrings;
}
int StringInstrument::GetNumOfFrets()
{
    return numFrets;
}
bool StringInstrument::GetIsBowed()
{
    return isBowed;
}
