#include "Artwork.h"
#include "Artist.h"
#include <iostream>

// TODO: Define default constructor
Artwork::Artwork() {
    title = "unknown";
    yearCreated = -1;
}

// TODO: Define second constructor to initialize
//       private fields (title, yearCreated, artist)
Artwork::Artwork(string userTitle, int yearCreated, Artist userArtist){
    this->title = userTitle;
    this->yearCreated = yearCreated;
    this->artist = userArtist;
}

// TODO: Define get functions: GetTitle(), GetYearCreated()
string Artwork::GetTitle() const{
    return title;
}

int Artwork::GetYearCreated() const{
    return yearCreated;
}

// TODO: Define PrintInfo() function
//       Call the PrintInfo() function in the Artist class to print an artist's information  
void Artwork::PrintInfo() const{
    artist.PrintInfo();
    cout << "Title: " << title << ", " << yearCreated << endl; 
}