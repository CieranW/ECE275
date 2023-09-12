#include <iostream>
using namespace std;

int main()
{
    string userInput;

    getline(cin, userInput);
    // Checks condition to keep going
    while (userInput != "Done" && userInput != "done" && userInput != "d")
    {
        // Loop to print out inputted word in reverse
        for (int i = userInput.size() - 1; i >= 0; i--)
        {
            cout << userInput.at(i);
        }
        cout << endl;
        getline(cin, userInput);
    }

    return 0;
}