#include <iostream>
#include <iomanip>
#include <cmath>
#include "Car.h"
using namespace std;

// TODO: Assign every variable to 0 in the default constructor
Car::Car()
{
    modelYear = 0;
    purchasePrice = 0;
    currentValue = 0;
}

// TODO: Write in Car(int modelEntered, int priceEntered, int valueEntered);
Car::Car(int modelEntered, int priceEntered, int valueEntered)
{
    modelYear = modelEntered;
    purchasePrice = priceEntered;
    currentValue = valueEntered;
}

void Car::SetModelYear(int userYear)
{
    modelYear = userYear;
}

int Car::GetModelYear() const
{
    return modelYear;
}

// TODO: Implement SetPurchasePrice() function
void Car::SetPurchasePrice(int userPrice)
{
    purchasePrice = userPrice;
}

// TODO: Implement GetPurchasePrice() function
int Car::GetPurchasePrice() const
{
    return purchasePrice;
}

void Car::CalcCurrentValue(int currentYear)
{
    double depreciationRate = 0.15;
    int carAge = currentYear - modelYear;

    // Car depreciation formula
    currentValue = purchasePrice * pow((1 - depreciationRate), carAge);
}

// TODO: Implement PrintInfo() function to output modelYear, purchasePrice, and currentValue
void Car::PrintInfo() const
{
    cout << "Model Year: " << modelYear << endl;
    cout << "Purchase Price: $" << purchasePrice << endl;
    cout << "Current Value: $" << currentValue << endl;
}