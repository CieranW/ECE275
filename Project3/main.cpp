#include "Graph.h"
#include "Project3a.h"
// include libraries that your code uses
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

///////////////// Before submitting your code
// 1) uncomment this part since zyBooks use it.
/*int main(int argc, const char* argv[]) {
    if (argc != 2)
    {
        std::cout << "./project3 inputFile" << std::endl;
        return EXIT_FAILURE;
    }
    string inputFileName = argv[1];*/

///////////////////// uncomment above befofre submitting on zyBooks /////////////////
// 2) Comment the next 2 lines below
int main(void)
{
    string inputFileName = "input1.txt"; // Do NOT change the name "inputFileName" since used above

    // Add your code //
    ifstream inputFile;
    inputFile.open(inputFileName);
    if (!inputFile.is_open())
    {
        cout << "Error opening " << inputFileName << endl;
        return EXIT_FAILURE;
    }

    string line;
    vector<Account> allAccounts;

    while (getline(inputFile, line))
    {
        stringstream ss(line);

        string accountName, followerName;

        ss >> accountName >> followerName;

        // Change both accountName and followerName to lowercase
        for (unsigned int i = 0; i < accountName.length(); i++)
        {
            accountName[i] = tolower(accountName[i]);
        }
        for (unsigned int i = 0; i < followerName.length(); i++)
        {
            followerName[i] = tolower(followerName[i]);
        }

        // Check if both the accountName and followerName exist in the master vector
        auto accountIt = find_if(allAccounts.begin(), allAccounts.end(),
                                 [&accountName](const Account &acc)
                                 { return acc.accountExists(accountName); });

        auto followerIt = find_if(allAccounts.begin(), allAccounts.end(),
                                  [&followerName](const Account &acc)
                                  { return acc.accountExists(followerName); });

        // If both accountName and followerName exist, add following relationship
        if (accountIt != allAccounts.end() && followerIt != allAccounts.end())
        {
            followerIt->addFollowing(accountName);
            accountIt->addFollower(followerName);
        }
        else
        {
            if (accountIt == allAccounts.end())
            {
                cout << "Creating new account for " << accountName << endl;
                Account newAccount(accountName);
                newAccount.addFollower(followerName);
                allAccounts.push_back(newAccount);
            }

            if (followerIt == allAccounts.end())
            {
                cout << "Creating new account for " << followerName << endl;
                Account newAccount(followerName);
                newAccount.addFollowing(accountName);
                allAccounts.push_back(newAccount);
            }
        }
    }

    // Print the follower count for each account in the master vector
    for (const auto &acc : allAccounts)
    {
        cout << "Account: " << acc.getAccountName() << ", Follower Count: " << acc.getFollowerCount() << endl;
        cout << "Follower: " << acc.getFollower() << endl;
    }

    return 0;
}

// To run
// g++ -std=c++11 -c main.cpp -o main.o && g++ -std=c++11 -c Project3a.cpp -o Project3a.o && g++ -std=c++11 main.o Project3a.o -o my_program && ./my_program