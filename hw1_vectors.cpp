#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Read customer information from external file
// Make no changes to the following code
void ReadCustomerData(vector<string> &names, vector<string> &states, vector<double> &debt)
{
    ifstream inFS;

    // Read all data from file into three parallel vectors
    try
    {
        inFS.open("CustomerData.csv");

        for (long unsigned index = 0; index < names.size(); ++index)
        {
            inFS >> names.at(index);  // last name
            inFS >> states.at(index); // state of residence
            inFS >> debt.at(index);   // amount of debt
        }
    }
    // What if data file not found?
    catch (string err)
    {
        cout << "Failed to read the data file: " << err << endl;
    }

    inFS.close();
}

int main()
{
    int size;

    // Input # of customers and create parallel vectors
    cin >> size;
    vector<string> names(size);
    vector<string> states(size);
    vector<double> debt(size);

    // Fill vectors with data from external file (described in another section)
    ReadCustomerData(names, states, debt);

    /* Type your code here */
    // Input debt limit, search phrase, and state

    return 0;
}
