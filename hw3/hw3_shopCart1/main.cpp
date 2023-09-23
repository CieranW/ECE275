#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main()
{

    /* Type your code here */
    string name;
    int price, quantity;
    ItemToPurchase item1, item2;

    cout << "Item 1\n"
         << "Enter the item name:\n";
    getline(cin, name);
    cout << "Enter the item price:\n";
    cin >> price;
    cout << "Enter the item quantity:\n";
    cin >> quantity;
    cout << endl;

    item1 = ItemToPurchase(name, price, quantity);

    cin.ignore();

    cout << "Item 2\n"
         << "Enter the item name:\n";
    getline(cin, name);
    cout << "Enter the item price:\n";
    cin >> price;
    cout << "Enter the item quantity:\n";
    cin >> quantity;
    cout << endl;

    item2 = ItemToPurchase(name, price, quantity);

    int item1Cost = item1.GetPrice() * item1.GetQuantity();
    int item2Cost = item2.GetPrice() * item2.GetQuantity();
    int totalCost = item1Cost + item2Cost;

    cout << "TOTAL COST\n";
    cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << item1Cost << endl;
    cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << item2Cost << endl;
    cout << "\nTotal: $" << totalCost << endl;

    return 0;
}