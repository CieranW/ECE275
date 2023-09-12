#include <iostream>
#include <string>
using namespace std;

int main()
{
    string login, first, last;
    int number;

    cin >> first;
    cin >> last;
    cin >> number;

    if (last.size() < 5)
    {
        last = last;
    }
    else
    {
        last = last.substr(0, 5);
    }

    first = first.at(0);
    number = number % 100;

    login = last + first + to_string(number);

    cout << login << endl;

    return 0;
}