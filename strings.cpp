#include <iostream>
#include <string>
using namespace std;

int main()
{
    string userInput;

    getline(cin, userInput);

    char lastChar = userInput.at(userInput.size() - 1);

    if (lastChar == '?')
    {
        cout << "A question" << endl;
    }
    else
    {
        cout << "Not a question" << endl;
    }

    return 0;
}