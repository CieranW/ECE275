#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

/* Type your code here */
ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string name, int price, int quantity)
{
    this->itemName = name;
    this->itemPrice = price;
    this->itemQuantity = quantity;
}

void ItemToPurchase::SetName(string name) { itemName = name; }

void ItemToPurchase::SetPrice(int price) { itemPrice = price; }

void ItemToPurchase::SetQuantity(int quantity) { itemQuantity = quantity; }

string ItemToPurchase::GetName() const { return itemName; }

int ItemToPurchase::GetPrice() const { return itemPrice; }

int ItemToPurchase::GetQuantity() const { return itemQuantity; }