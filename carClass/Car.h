#ifndef CARH
#define CARH

class Car
{
private:
    int modelYear;
    // TODO: Declare purchasePrice member (int)
    int purchasePrice;
    double currentValue;

public:
    // TODO: Create a default constructor
    Car();

    // TODO: Additional constructor
    Car(int modelEntered, int priceEntered, int valueEntered);

    void SetModelYear(int userYear);

    int GetModelYear() const;

    // TODO: Declare SetPurchasePrice() function
    void SetPurchasePrice(int userPrice);

    // TODO: Declare GetPurchasePrice() function
    int GetPurchasePrice() const;

    void CalcCurrentValue(int currentYear);

    // TODO: Declare PrintInfo() method to output modelYear, purchasePrice, and currentValue
    void PrintInfo() const;
};

#endif