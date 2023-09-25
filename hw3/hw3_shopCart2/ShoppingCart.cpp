#include <iostream>
#include <string>
#include <vector>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

ShoppingCart::ShoppingCart()
{
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date)
{
    this->customerName = name;
    this->currentDate = date;
}

string ShoppingCart::GetCustomerName() const { return customerName; }

string ShoppingCart::GetDate() const { return currentDate; }

int ShoppingCart::GetNumItemsInCart() const
{
    int numItems = 0;

    for (size_t i = 0; i < cartItems.size(); i++)
    {
        numItems += cartItems[i].GetQuantity();
    }

    return numItems;
}

int ShoppingCart::GetCostOfCart() const
{
    int totalCost = 0;

    for (size_t i = 0; i < cartItems.size(); i++)
    {
        totalCost += cartItems[i].GetQuantity() * cartItems[i].GetPrice();
    }

    return totalCost;
}

void ShoppingCart::AddItem(ItemToPurchase item)
{
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string itemName)
{
    bool itemFound = false;

    for (size_t i = 0; i < cartItems.size(); ++i)
    {
        if (cartItems[i].GetName() == itemName)
        {
            cartItems.erase(cartItems.begin() + i);
            itemFound = true;
            break;
        }
    }

    if (!itemFound)
    {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::ModifyItem(ItemToPurchase item)
{
    bool itemFound = false;

    for (size_t i = 0; i < cartItems.size(); ++i)
    {
        if (cartItems[i].GetName() == item.GetName())
        {
            cartItems[i].SetPrice(item.GetPrice());

            itemFound = true;
            break;
        }
    }

    if (!itemFound)
    {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

void ShoppingCart::PrintTotal()
{
    cout << endl
         << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl
         << endl;

    if (GetNumItemsInCart() == 0)
    {
        cout << "SHOPPING CART IS EMPTY\n";
    }
    else
    {
        for (size_t i = 0; i < cartItems.size(); i++)
        {
            cout << cartItems[i].GetName() << " " << cartItems[i].GetQuantity() << " @ $" << cartItems[i].GetPrice() << " = $" << cartItems[i].GetQuantity() * cartItems[i].GetPrice() << endl;
        }
    }
    cout
        << endl;
    cout << "Total: $" << GetCostOfCart()
         << endl;
}

void ShoppingCart::PrintDescriptions()
{
    cout << endl
         << customerName << "'s Shopping Cart - " << currentDate << endl;

    cout << "\nItem Descriptions\n";
    for (size_t i = 0; i < cartItems.size(); i++)
    {
        cout << cartItems[i].GetName() << ": " << cartItems[i].GetDescription() << endl;
    }
}

ItemToPurchase ShoppingCart::GetItemByName(const string &itemName) const
{
    for (const auto &item : cartItems)
    {
        if (item.GetName() == itemName)
        {
            return item;
        }
    }

    return ItemToPurchase("NOT_FOUND", "", 0, 0); // Item not found
}
