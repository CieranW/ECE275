#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

/* Type your code here */
ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
    itemDescription = "none";
}

ItemToPurchase::ItemToPurchase(string name, int price, int quantity, string description)
{
    this->itemName = name;
    this->itemPrice = price;
    this->itemQuantity = quantity;
    this->itemDescription = description;
}

void ItemToPurchase::SetName(string name) { itemName = name; }

void ItemToPurchase::SetPrice(int price) { itemPrice = price; }

void ItemToPurchase::SetQuantity(int quantity) { itemQuantity = quantity; }

void ItemToPurchase::SetDescription(string description) { itemDescription = description; }

string ItemToPurchase::GetName() const { return itemName; }

int ItemToPurchase::GetPrice() const { return itemPrice; }

int ItemToPurchase::GetQuantity() const { return itemQuantity; }

string ItemToPurchase::GetDescription() const { return itemDescription; }

void ItemToPurchase::PrintItemCost() const
{
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity * itemPrice << endl;
}

void ItemToPurchase::PrintItemDescription() const
{
    cout << itemName << ": " << itemDescription << ".\n";
}