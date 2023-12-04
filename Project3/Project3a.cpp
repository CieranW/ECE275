#include "Project3a.h"
#include "Graph.h"
#include <string>
#include <vector>
#include <algorithm>

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

string Account::getFollower() const
{
    string followList = "";
    for (const auto &follower : followers)
    {
        followList += follower + " ";
    }
    return followList;
}

vector<string> Account::getFollowerList() const
{
    // Sort alphabetically
    vector<string> sortedFollowers = followers;
    sort(sortedFollowers.begin(), sortedFollowers.end());
    return sortedFollowers;
}

int Account::getFollowerCount() const
{
    return followerCount;
}