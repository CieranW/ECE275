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
// int main(int argc, const char *argv[])
// {
//     if (argc != 2)
//     {
//         std::cout << "./project3 inputFile" << std::endl;
//         return EXIT_FAILURE;
//     }
//     string inputFileName = argv[1];

///////////////////// uncomment above befofre submitting on zyBooks /////////////////
// 2) Comment the next 2 lines below
int main(void)
{
    string inputFileName = "input7.txt"; // Do NOT change the name "inputFileName" since used above

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
    vector<string> allAccountNames;
    int networkSize = 0;

    while (getline(inputFile, line))
    {
        stringstream ss(line);

        string accountName, followerName;
        ss >> accountName >> followerName;

        // Change name to lowercase
        transform(accountName.begin(), accountName.end(), accountName.begin(), ::tolower);
        transform(followerName.begin(), followerName.end(), followerName.begin(), ::tolower);

        // Check if both accountName and followerName exist in the master vector
        auto accountIt = find_if(allAccounts.begin(), allAccounts.end(),
                                 [&accountName](const Account &acc)
                                 { return acc.accountExists(accountName); });

        auto followerIt = find_if(allAccounts.begin(), allAccounts.end(),
                                  [&followerName](const Account &acc)
                                  { return acc.accountExists(followerName); });

        if (accountIt == allAccounts.end() && followerIt == allAccounts.end())
        {
            Account newAccount(accountName);
            allAccounts.push_back(newAccount);

            Account newFollower(followerName);
            allAccounts.push_back(newFollower);
        }
        else if (accountIt == allAccounts.end())
        {
            Account newAccount(accountName);
            allAccounts.push_back(newAccount);
        }
        else if (followerIt == allAccounts.end())
        {
            Account newFollower(followerName);
            allAccounts.push_back(newFollower);
        }
        // Re-find iterators after possible vector reallocation
        accountIt = find_if(allAccounts.begin(), allAccounts.end(),
                            [&accountName](const Account &acc)
                            { return acc.accountExists(accountName); });

        followerIt = find_if(allAccounts.begin(), allAccounts.end(),
                             [&followerName](const Account &acc)
                             { return acc.accountExists(followerName); });

        // Establish follower/following relationship
        if (accountIt != allAccounts.end() || followerIt != allAccounts.end())
        {
            accountIt->addFollower(followerName);
            followerIt->addFollowing(accountName);

            // cout << followerName << " is now following " << accountName << endl;
        }
    }

    // For testing purposes
    // Print the follower count for each account in the master vector
    // for (const auto &acc : allAccounts)
    // {
    //     cout << "Account: " << acc.getAccountName() << ", Follower Count: " << acc.getFollowerCount() << endl;
    //     cout << "Follower: " << acc.getFollower() << endl;
    // }

    // Find the maximum number of followers
    int maxFollowers = 0;
    for (const auto &acc : allAccounts)
    {
        maxFollowers = max(maxFollowers, acc.getFollowerCount());
    }

    // Create a vector to store accounts with maximum followers
    vector<Account> accountsWithMaxFollowers;

    // Find all accounts with the maximum number of followers
    for (const auto &acc : allAccounts)
    {
        if (acc.getFollowerCount() == maxFollowers)
        {
            accountsWithMaxFollowers.push_back(acc);
        }
    }

    // Sort accounts with the maximum followers alphabetically
    sort(accountsWithMaxFollowers.begin(), accountsWithMaxFollowers.end(), [](const Account &a, const Account &b)
         { return a.getAccountName() < b.getAccountName(); });

    // Get the account with the highest followers and the highest alphabetical order
    Account accountWithMostFollowers = accountsWithMaxFollowers[0];

    // Print the account with the most followers and its followers
    cout << "The root user is " << accountWithMostFollowers.getAccountName() << ", with in-degree centrality of " << accountWithMostFollowers.getFollowerCount() << "." << endl;
    cout << "There are " << allAccounts.size() << " users in the social network." << endl;
    cout << accountWithMostFollowers.getAccountName() << " (0)" << endl;

    for (int i = 0; i < accountWithMostFollowers.getFollowerCount(); i++)
    {
        cout << accountWithMostFollowers.getFollowerList()[i] << " (1)" << endl;
        Account follower = accountWithMostFollowers.getFollowerList()[i];
        for (const auto &acc : allAccounts)
        {
            if (acc.getAccountName() == follower.getAccountName())
            {
                for (const auto &follower : acc.getFollowerList())
                {
                    cout << follower << " (2)" << endl;
                }
            }
        }
    }

    inputFile.close();
    return 0;
}

// To run
// g++ -std=c++11 -c main.cpp -o main.o && g++ -std=c++11 -c Project3a.cpp -o Project3a.o && g++ -std=c++11 main.o Project3a.o -o my_program && ./my_program