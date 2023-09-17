#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFS;
    int Num;

    cout << "Opening file numFile.txt\n";

    inFS.open("numFile.txt");
    if (!inFS.is_open())
    {
        cout << "Could not open file\n";
        return 1;
    }

    while (!inFS.fail())
    {
        cout << "Num: " << Num << endl;
        inFS >> Num;
    }

    if (!inFS.eof())
    {
        cout << "Input failure" << endl;
    }

    cout << "Closing file" << endl;
    inFS.close();

    return 0;
}