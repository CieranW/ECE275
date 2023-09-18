#include "Artist.h"
#include <iostream>
#include <string>
using namespace std;

// TODO: Define default constructor
Artist::Artist()
{
    artistName = "unknown";
    birthYear = -1;
    deathYear = -1;
}

// TODO: Define second constructor to initialize
//       private fields (artistName, birthYear, deathYear)
Artist::Artist(string userArtistName, int userBirthYear, int userDeathYear)
{
    this->artistName = userArtistName;
    this->birthYear = userBirthYear;
    this->deathYear = userDeathYear;
}

// TODO: Define get functions: GetName(), GetBirthYear(), GetDeathYear()
string Artist::GetName() const
{
    return artistName;
}

int Artist::GetBirthYear() const
{
    return birthYear;
}

int Artist::GetDeathYear() const
{
    return deathYear;
}

// TODO: Define PrintInfo() function
//      If deathYear is entered as -1, only print birthYear
void Artist::PrintInfo() const
{
    // Outputs Artist: artistName (birthYear to deathYear/present)
    cout << "Artist: " << artistName;
    if (deathYear == -1 && birthYear > 0)
    {
        cout << " (" << birthYear << " to present)";
    }
    else if (deathYear > 0 && birthYear > 0)
    {
        cout << " (" << birthYear << " to " << deathYear << ")";
    }
    else
    {
        cout << " (unknown)";
    }
    cout << endl;
}