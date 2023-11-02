#include <iostream>
#include <set>
#include <string>
using namespace std;
void print_set(set<string> myset)
{
    cout << "\nPrint an entire set" << endl;
    for (auto bb : myset)
        cout << bb << endl;
}
int main()
{
    set<string> books;
    string userInput;
    cin >> userInput;
    unsigned int i = 1;
    string tt;

    while (userInput != "done")
    {
        if (books.insert(userInput).second)
        {
            cout << "OK" << endl;
        }
        else
        {
            i = 1;
            while (true)
            {
                if (books.insert(userInput + to_string(i)).second)
                {
                    cout << "OK" << endl;
                    break;
                }
                else
                {
                    tt = userInput + to_string(i);
                    books.insert(tt);
                    cout << tt << endl;
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
