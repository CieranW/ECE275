#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

typedef struct city_struct
{
    string name;
    string state;
    double percent;
} city_t;

void init_vector(vector<city_t> &cityvector);

void init_vector(vector<city_t> &cityvector)
{
    cityvector.at(0) = {"Cape Coral", "FL", 6.4};
    cityvector.at(1) = {"Santa Cruz", "CA", 12.5};
    cityvector.at(2) = {"Westfield", "IN", 7.7};
    cityvector.at(3) = {"Georgetown", "TX", 14.4};
    cityvector.at(4) = {"Little Elm", "TX", 8.0};
    cityvector.at(5) = {"Queen Creek", "AZ", 6.7};
    cityvector.at(6) = {"Lehi", "UT", 5.6};
    cityvector.at(7).name = "Leander";
    cityvector.at(7).state = "TX";
    cityvector.at(7).percent = 10.9;
}

int main()
{
    int i;
    vector<city_t> allCities(8);

    init_vector(allCities);

    cout << "Cities with growth < 8%:" << endl;
    for (i = 0; i < allCities.size(); i++)
    {
        if (allCities.at(i).percent < 8.0)
            cout << allCities.at(i).name << endl;
    }

    cout << "Cities in TX:" << endl;
    for (i = 0; i < allCities.size(); i++)
    {
        if (allCities.at(i).state == "TX")
            cout << allCities.at(i).name << ", " << allCities.at(i).percent << "%" << endl;
    }
    return 0;
}
