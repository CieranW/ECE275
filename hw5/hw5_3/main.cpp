#include "Book.h"
#include "Encyclopedia.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    Book myBook;
    Encyclopedia myEncyclopedia;

    string title, author, publisher, publicationDate;
    string eTitle, eAuthor, ePublisher, ePublicationDate, edition;
    int numPages;

    getline(cin, title);
    getline(cin, author);
    getline(cin, publisher);
    getline(cin, publicationDate);

    getline(cin, eTitle);
    getline(cin, eAuthor);
    getline(cin, ePublisher);
    getline(cin, ePublicationDate);
    getline(cin, edition);
    cin >> numPages;

    myBook.SetTitle(title);
    myBook.SetAuthor(author);
    myBook.SetPublisher(publisher);
    myBook.SetPublicationDate(publicationDate);
    myBook.PrintInfo();

    myEncyclopedia.SetTitle(eTitle);
    myEncyclopedia.SetAuthor(eAuthor);
    myEncyclopedia.SetPublisher(ePublisher);
    myEncyclopedia.SetPublicationDate(ePublicationDate);
    myEncyclopedia.SetEdition(edition);
    myEncyclopedia.SetNumPages(numPages);
    myEncyclopedia.PrintInfo();

    return 0;
}
// To run this program, type:
// g++ -c main.cpp -o main.o && g++ -c Book.cpp -o Book.o && g++ -c Encyclopedia.cpp -o Encyclopedia.o && g++ main.o Book.o Encyclopedia.o -o my_program && ./my_program