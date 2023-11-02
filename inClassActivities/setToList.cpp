#include <iostream>
#include <list>
#include <string>
using namespace std;
void print_set(list<string> myset)
{
    cout << "\nPrint an entire set" << endl;
    for (auto bb : myset)
        cout << bb << endl;
}
int main()
{
    list<string> books;
    list<string>::iterator it;
    string userInput;
    unsigned int i = 1;
    string tt;

    cin >> userInput;

    while (userInput != "done")
    {
        if (find(books.begin(), books.end(), userInput) == books.end())
        {
            // not in the list, add to the list
            books.push_back(userInput);
            cout << "OK" << endl;
        }
        else
        {
            // in the list, modify it unitl it is unqiue and add to the list
            i = 1;
            while (true)
            {
                if (find(books.begin(), books.end(), userInput + to_string(i)) == books.end())
                {
                    // not in the list, add to the list
                    books.push_back(userInput + to_string(i));
                    break;
                }
                else
                {
                    i++;
                }
            }
        }
        cin >> userInput;
    }
    cout << "Size: " << books.size() << endl;
    print_set(books);
    return 0;
}
