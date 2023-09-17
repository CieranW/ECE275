#include "Artist.h"
#include "Artwork.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string userTitle, userArtistName;
    int yearCreated, userBirthYear, userDeathYear;

    getline(cin, userArtistName);
    getline(cin, userTitle);
    cin >> userBirthYear;
    cin >> userDeathYear;
    cin >> yearCreated;

    Artist userArtist = Artist(userArtistName, userBirthYear, userDeathYear);

    Artwork newArtwork = Artwork(userTitle, yearCreated, userArtist);

    newArtwork.PrintInfo();
}