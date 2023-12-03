#ifndef PROJECT3A_H
#define PROJECT3A_H

#include <stdio.h>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Account
{
public:
    Account(string accountName);
    void addFollower(const string &followerName);
    void addFollowing(const string &followingName);
    bool accountExists(const string &accountName) const;
    string getAccountName() const;
    int getFollowerCount() const;

private:
    string name;
    vector<string> followers;
    vector<string> following;
    int followerCount;
};

#endif /* PROJECT3A_H */