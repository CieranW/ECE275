#include "StringInstrument.h"

int main()
{
    Instrument myInstrument;
    StringInstrument myStringInstrument;

    string instrumentName, manufacturerName, stringInstrumentName, stringManufacturer;
    int yearBuilt, cost, stringYearBuilt, stringCost, numStrings, numFrets;
    bool bowed;

    cin >> instrumentName;
    cin >> manufacturerName;
    cin >> yearBuilt;
    cin >> cost;

    cin >> stringInstrumentName;
    cin >> stringManufacturer;
    cin >> stringYearBuilt;
    cin >> stringCost;
    cin >> numStrings;
    cin >> numFrets;
    cin >> bowed;

    myInstrument.SetName(instrumentName);
    myInstrument.SetManufacturer(manufacturerName);
    myInstrument.SetYearBuilt(yearBuilt);
    myInstrument.SetCost(cost);
    myInstrument.PrintInfo();

    myStringInstrument.SetName(stringInstrumentName);
    myStringInstrument.SetManufacturer(stringManufacturer);
    myStringInstrument.SetYearBuilt(stringYearBuilt);
    myStringInstrument.SetCost(stringCost);
    myStringInstrument.SetNumOfStrings(numStrings);
    myStringInstrument.SetNumOfFrets(numFrets);
    myStringInstrument.SetIsBowed(bowed);
    myStringInstrument.PrintInfo();

    cout << "   Number of strings: " << myStringInstrument.GetNumOfStrings() << endl;
    cout << "   Number of frets: " << myStringInstrument.GetNumOfFrets() << endl;
    cout << "   Is bowed: " << boolalpha << myStringInstrument.GetIsBowed() << endl;
}