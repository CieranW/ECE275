#ifndef STR_INSTRUMENTH
#define STR_INSTRUMENTH

#include "Instrument.h"

class StringInstrument : public Instrument
{
    // TODO: Declare private data members: numStrings, numFrets, isBowed
private:
    int numStrings;
    int numFrets;
    bool isBowed;

    // TODO: Declare mutator functions - SetNumOfStrings(), SetNumOfFrets(), SetIsBowed()
public:
    void SetNumOfStrings(int userNumStrings);
    void SetNumOfFrets(int userNumFrets);
    void SetIsBowed(bool userIsBowed);
    // TODO: Declare accessor functions - GetNumOfStrings(), GetNumOfFrets(), GetIsBowed()
    int GetNumOfStrings();
    int GetNumOfFrets();
    bool GetIsBowed();
};

#endif
