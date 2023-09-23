#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

/* Type your code here */
class ItemToPurchase
{
public:
    ItemToPurchase();
    ItemToPurchase(string name, int price, int quantity);

    void SetName(string name);
    void SetPrice(int price);
    void SetQuantity(int quantity);

    string GetName() const;
    int GetPrice() const;
    int GetQuantity() const;

private:
    string itemName;
    int itemQuantity;
    int itemPrice;
};

#endif