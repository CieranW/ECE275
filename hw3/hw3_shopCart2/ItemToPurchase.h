#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>
using namespace std;

/* Type your code here */
class ItemToPurchase
{
public:
    ItemToPurchase();
    ItemToPurchase(string name, string description, int price, int quantity);

    void SetName(string name);
    void SetPrice(int price);
    void SetQuantity(int quantity);
    void SetDescription(string description);

    string GetName() const;
    int GetPrice() const;
    int GetQuantity() const;
    string GetDescription() const;

    void PrintItemCost() const;
    void PrintItemDescription() const;

private:
    string itemName;
    string itemDescription;
    int itemQuantity;
    int itemPrice;
};

#endif