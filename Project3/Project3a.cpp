#include "Project3a.h"
#include "Graph.h"
#include <string>
#include <map>

using namespace std;

Account::Account(string accountName)
{
    name = accountName;
    followerCount = 0;
}

void Account::addFollower(const string &followerName)
{
    followers.push_back(followerName);
    followerCount++;
}

void Account::addFollowing(const string &followingName)
{
    following.push_back(followingName);
}

bool Account::accountExists(const string &accountName) const
{
    return name == accountName;
}

string Account::getAccountName() const
{
    return name;
}

int Account::getFollowerCount() const
{
    return followerCount;
}