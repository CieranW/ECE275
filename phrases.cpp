#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1, str2;

    getline(cin, str1);
    getline(cin, str2);

    if (str1 == str2)
    {
        cout << "Both phrases match" << endl;
    }
    else if (str1.find(str2) != string::npos)
    {
        cout << str2 << " is found within " << str1 << endl;
    }
    else if (str2.find(str1) != string::npos)
    {
        cout << str1 << " is found within " << str2 << endl;
    }
    else
    {
        cout << "No match" << endl;
    }

    return 0;
}