#include <iostream>
#include <string>
#include <vector>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

ShoppingCart::ShoppingCart(){customerName("none"), currentDate("January 1, 2016")}

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
        numItems += cartItemsa[i].GetQuantity();
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
            // Check if the provided item has default values, if not, modify the item in cart
            if (item.GetDescription() != "none")
            {
                cartItems[i].SetDescription(item.GetDescription());
            }
            if (item.GetPrice() > 0)
            {
                cartItems[i].SetPrice(item.GetPrice());
            }
            if (item.GetQuantity() > 0)
            {
                cartItems[i].SetQuantity(item.GetQuantity());
            }

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
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of items: " << GetNumItemsInCart() << endl
         << endl;

    for (size_t i = 0; i < cartItems.size(); i++)
    {
        cout << cartItems[i].GetName() << cartItems[i].GetQuantity() << " @ $" << cartItems[i].GetPrice() << " = $" << cartItems[i].GetQuantity() * cartItems[i].GetPrice() << endl;
    }

    cout << endl
         << endl;
    cout << "Total: $" << GetCostOfCart() << endl;
}

void ShoppingCart::PrintDescriptions()
{
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;

    cout << "\nItem Descriptions\n";
    for (size_t i = 0; i < cartItems.size(); i++)
    {
        cout << cartItems[i].GetName() << ": " << cartItems[i].GetDescription() << endl;
    }
}