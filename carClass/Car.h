#ifndef CARH
#define CARH

class Car
{
private:
    int modelYear;
    // TODO: Declare purchasePrice member (int)
    double currentValue;

public:
    void SetModelYear(int userYear);

    int GetModelYear() const;

    // TODO: Declare SetPurchasePrice() function

    // TODO: Declare GetPurchasePrice() function

    void CalcCurrentValue(int currentYear);

    // TODO: Declare PrintInfo() method to output modelYear, purchasePrice, and
    // currentValue
};

#endif