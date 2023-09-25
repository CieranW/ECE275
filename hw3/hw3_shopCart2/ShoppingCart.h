#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart
{
public:
    ShoppingCart();
    ShoppingCart(string name, string date);

    string GetCustomerName() const;
    string GetDate() const;
    int GetNumItemsInCart() const;
    int GetCostOfCart() const;

    void AddItem(ItemToPurchase item);
    void RemoveItem(string itemName);
    void ModifyItem(ItemToPurchase item);

    void PrintTotal();
    void PrintDescriptions();

private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
};
#endif