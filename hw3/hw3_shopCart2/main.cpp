#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

void ExecuteMenu(char option, ShoppingCart &theCart);

void PrintMenu(ShoppingCart &theCart)
{
    char option;
    bool repeatPrompt = false;
    /* Type your code here */
    while (true)
    {
        if (repeatPrompt)
        {
            cout << "\nChoose an option:";
            repeatPrompt = false; // Reset the flag
        }
        else
        {
            // Menu options printed
            cout << "MENU\n";
            cout << "a - Add item to cart\n";
            cout << "d - Remove item from cart\n";
            cout << "c - Change item quantity\n";
            cout << "i - Output items' descriptions\n";
            cout << "o - Output shopping cart\n";
            cout << "q - Quit\n";

            // Get user option based on above menu
            cout << "\nChoose an option:";
        }

        cin >> option;

        // If q is called, exit loop
        if (option == 'q')
        {
            cout << endl;
            return;
        }
        else
        {
            switch (option)
            {
            // Else call ExecuteMenu() to implement the options listed
            case 'a':
            case 'd':
            case 'c':
            case 'i':
            case 'o':
                cout << endl;
                ExecuteMenu(option, theCart);
                break;

            default:
                repeatPrompt = true; // Set the flag to repeat the prompt
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
    }
}

void ExecuteMenu(char option, ShoppingCart &theCart)
{
    /* Type your code here */
    string itemName, itemDescription;
    int itemPrice, itemQuantity;
    switch (option)
    {
    case 'a':
    {
        // Implement AddItem()
        cin.ignore(); // Clear buffer
        cout << "ADD ITEM TO CART\n";
        cout << "Enter the item name:\n";
        getline(cin, itemName);
        cout << "Enter the item description:\n";
        getline(cin, itemDescription);
        cout << "Enter the item price:\n";
        cin >> itemPrice;
        cout << "Enter the item quantity:\n";
        cin >> itemQuantity;
        ItemToPurchase newItem(itemName, itemDescription, itemPrice, itemQuantity);
        theCart.AddItem(newItem);
        break;
    }
    case 'd':
    {
        // Implement RemoveItem()
        cout << "REMOVE ITEM FROM CART\n";
        cout << "Enter name of item to remove:\n";
        cin.ignore(); // Clear buffer
        getline(cin, itemName);
        theCart.RemoveItem(itemName);
        break;
    }
    case 'c':
    {
        // Implement ModifyItem()
        cin.ignore(); // Clear buffer
        cout << "CHANGE ITEM QUANTITY\n";
        cout << "Enter the item name:\n";
        getline(cin, itemName);
        // TODO: Somehow recall the item's description and price through the name.
        // Find the item in the cart based on its name
        ItemToPurchase modifiedItem = theCart.GetItemByName(itemName);
        itemDescription = modifiedItem.GetDescription();
        itemPrice = modifiedItem.GetPrice();

        cout << "Enter the new quantity:\n";
        cin >> itemQuantity;
        // Check if the item was found
        if (modifiedItem.GetName() != "NOT_FOUND")
        {
            modifiedItem.SetQuantity(itemQuantity);
            // Update the item's quantity
            ItemToPurchase modifiedItem(itemName, itemDescription, itemPrice, itemQuantity);

            // Modify the item in the cart
            theCart.ModifyItem(modifiedItem);
        }
        else
        {
            cout << "Item not found in cart. Nothing modified." << endl;
        }
        break;
    }
    case 'i':
        // Call PrintDescriptions()
        cout << "OUTPUT ITEMS' DESCRIPTIONS";
        theCart.PrintDescriptions();
        break;

    case 'o':
        // Call PrintCart()
        cout << "OUTPUT SHOPPING CART";
        theCart.PrintTotal();
        break;
    }
    cout << endl;
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
    cout << "\nCustomer name: " << name << endl;
    cout << "Today's date: " << date << endl
         << endl;

    // Adding name and date to cart
    ShoppingCart cart(name, date);

    // Calling PrintMenu
    PrintMenu(cart);
    return 0;
}