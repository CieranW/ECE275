#include "Encyclopedia.h"
#include <iostream>

// Define functions declared in Encyclopedia.h
void Encyclopedia::SetEdition(string userEdition)
{
    edition = userEdition;
}

void Encyclopedia::SetNumPages(int userNumPages)
{
    numPages = userNumPages;
}

string Encyclopedia::GetEdition()
{
    return edition;
}

int Encyclopedia::GetNumPages()
{
    return numPages;
}

void Encyclopedia::PrintInfo()
{
    Book::PrintInfo();
    cout << "   Edition: " << edition << endl;
    cout << "   Number of Pages: " << numPages << endl;
}