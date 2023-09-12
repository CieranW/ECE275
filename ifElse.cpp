#include <iostream>

using namespace std;

int main()
{
    // Variables
    int highwayNumber;
    cout << "Enter highway number: ";
    cin >> highwayNumber;

    // Verify if the highway is a primary or auxiliary
    if (highwayNumber <= 99 && highwayNumber >= 1)
    {
        // Identifies if the highway goes east/west or north/south
        if (highwayNumber % 2 == 0)
        {
            cout << "I-" << highwayNumber << " is primary, going east/west.";
        }
        else
        {
            cout << "I-" << highwayNumber << " is primary, going north/south.";
        }
    }
    // If auxiliary, identifies north/south or east/west
    else if (highwayNumber > 100 && highwayNumber <= 999)
    {
        if (highwayNumber % 2 == 0 && highwayNumber % 100 != 0)
        {
            cout << "I-" << highwayNumber << " is auxiliary, serving I-" << highwayNumber % 100 << ", going east/west.";
        }
        else if (highwayNumber % 2 != 0 && highwayNumber % 100 != 0)
        {
            cout << "I-" << highwayNumber << " is auxiliary, serving I-" << highwayNumber % 100 << ", going north/south.";
        }
        else
        {
            cout << highwayNumber << " is not a valid highway number.";
        }
    }
    // If 100 or greater than 1000, says invalid.
    else
    {
        cout << highwayNumber << " is not a valid highway number.";
    }

    return 0;
}