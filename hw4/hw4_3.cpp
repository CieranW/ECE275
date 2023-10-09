#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

/* Define your function here */
double StepsToMiles(int userSteps)
{
    if (userSteps < 0)
    {
        throw invalid_argument("Exception: Negative step count entered.");
    }
    return static_cast<double>(userSteps) / 2000;
}

int main()
{

    /* Type your code here. */
    int userSteps;
    double userMiles;

    cin >> userSteps;

    try
    {
        userMiles = StepsToMiles(userSteps);
        cout << fixed << setprecision(2) << userMiles << endl;
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
