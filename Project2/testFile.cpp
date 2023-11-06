#include <iostream>
#include <fstream>
#include <string>

using namespace std; // Include the std namespace

int main()
{
    string file1Name = "outputFile5_Solution.txt";
    string file2Name = "outputFile5.txt";

    ifstream file1(file1Name);
    ifstream file2(file2Name);

    if (!file1.is_open() || !file2.is_open())
    {
        cerr << "Error: Unable to open one or both files." << endl;
        return 1;
    }

    string line1, line2;
    int lineCount = 1;
    bool filesAreEqual = true;

    while (getline(file1, line1) && getline(file2, line2))
    {
        if (line1 != line2)
        {
            cout << "Files differ at line " << lineCount << ":" << endl;
            cout << "File 1: " << line1 << endl;
            cout << "File 2: " << line2 << endl;
            filesAreEqual = false;
            break;
        }
        lineCount++;
    }

    if (filesAreEqual)
    {
        cout << "Files are identical." << endl;
    }

    file1.close();
    file2.close();

    return 0;
}
