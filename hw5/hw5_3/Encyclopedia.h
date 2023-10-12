#ifndef ENCYCLOPEDIAH
#define ENCYCLOPEDIAH

#include "Book.h"

class Encyclopedia : public Book
{
public:
    // TODO: Declare mutator functions - SetEdition(), SetNumPages()
    void SetEdition(string userEdition);
    void SetNumPages(int userNumPages);

    // TODO: Declare accessor functions - GetEdition(), GetNumPages()
    string GetEdition();
    int GetNumPages();

    // TODO: Declare a PrintInfo() function that overrides the PrintInfo() in Book class
    void PrintInfo();

    // TODO: Declare private data members
private:
    string edition;
    int numPages;
};

#endif