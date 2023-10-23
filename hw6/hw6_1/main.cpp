#include "ListItem.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;

int main () {
   // TODO: Declare a list called shoppingList of type ListItem
   list<ListItem> shoppingList;
   string item;

   // TODO: Read inputs (items) and add them to the shoppingList list
   //       Read inputs until a -1 is input
   getline(cin, item);
   while (item != "-1") {
      shoppingList.push_back(ListItem(item));
      getline(cin, item);
   }


   // TODO: Print the shoppingList list using the PrintNodeData() function

   for (list<ListItem>::iterator it = shoppingList.begin(); it != shoppingList.end(); ++it) {
      it->PrintNodeData();
   }

   return 0;
}

// To run program
//g++ -c main.cpp -o main.o && g++ -c ListItem.cpp -o ListItem.o && g++ main.o ListItem.o -o my_program && ./my_program