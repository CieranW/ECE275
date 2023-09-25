#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

void PrintMenu(ShoppingCart item)
{
    char option;
    /* Type your code here */
    while (1)
    {
        // Menu options printed
        cout << "a - Add item to cart\n";
        cout << "d - Remove item from cart\n";
        cout << "c - Change item quantity\n";
        cout << "i - Output items' descriptions\n";
        cout << "o - Output shopping cart\n";
        cout << "q - Quit\n";

        // Get user option based on above menu
        cout << "\nChoose an option:\n";
        cin >> option;
        // Switch options
        switch (option)
        {
        case 'a':
            // Call AddItem()
            AddItem();
            break;
        case 'd':
            // Call RemoveItem()
            RemoveItem();
            break;
        case 'c':
            // Call ModifyItem()
            ModifyItem();
            break;
        case 'i':
            // Call PrintDescriptions()
            PrintDescriptions();
            break;
        case 'o':
            // Call PrintCart()
            PrintTotal();
            break;
        case 'q':
            return;
        default:
            cout << "Invalid option - pick another\n";
            break;
        }
    }
}

void ExecuteMenu(char option, ShoppingCart &theCart)
{
    /* Type your code here */
}

int main()
{
    /* Type your code here */
    // Variables
    string name, date;

    // Prompt user for customer name and the date.
    cout << "Enter customer's name:\n";
    getline(cin, name);
    cout << "Enter today's date:\n";
    getline(cin, date);

    // Prints out the above information
    cout << "Customer name: " << name << endl;
    cout << "Today's date: " << date << endl;

    // Calling PrintMenu()
    PrintMenu();
    return 0;
}