#include <iostream>
#include "Car.h"
using namespace std;

int main()
{
    int userYear;
    int userPrice;
    int userCurrentYear;
    Car myCar;

    cin >> userYear;
    cin >> userPrice;
    cin >> userCurrentYear;

    // TODO: Check again and verify
    Car(userYear, userPrice, userCurrentYear);
    // Is it Car ourCar{2300, 1230, 453} ?

    myCar.SetModelYear(userYear);
    myCar.SetPurchasePrice(userPrice);
    myCar.CalcCurrentValue(userCurrentYear);

    myCar.PrintInfo();

    return 0;
}