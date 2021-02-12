#include <iostream>
#include "ShoppingCart.h"

using namespace std;

/* Functions used in main as defined:
 * outputShopper takes parameter ShoppingCart object and outputs customer's name and date
 * checkInput takes parameter char selection and utilizes recursion to sanitize to valid selection chars
 * void printMenu takes parameter ShoppingCart object and outputs the correct selection
 */

void outputShopper(ShoppingCart&); 
void checkInput(char&);
void printMenu(ShoppingCart&);

int main() {

    // Initalize name and date parameters to pass into ShoppingCart object intialized as 'user'
    string userName;
    string currDate;

    cout << "Enter customer's name: ";
    getline(cin, userName);
    cout << endl;

    cout << "Enter today's date: ";
    getline(cin, currDate);
    cout << endl;

    ShoppingCart user(userName, currDate);

    // Print the customer name and date
    // Load the menu screen
    outputShopper(user);
    printMenu(user);

    return 0;
}

void outputShopper(ShoppingCart& user) {

    // Prints name and date using ShoppingCart public accessors
    cout << endl << "Customer name: " << user.customerName() << endl;
    cout << "Today's date: " << user.date() << endl;
    cout << endl;
}

void checkInput(char& nav) {

    // Enter a char navigation (nav) tool
    cout << "Choose an option: ";
    cin >> nav;
    cout << endl;

    // If nav does not equal to any of the valid character,
    // use recursion to call the func until a valid character is returned
    if(nav != 'a' && nav != 'd' && nav != 'c' && nav != 'i' && nav != 'o' && nav != 'q') {
        checkInput(nav);
    }
}

 void printMenu(ShoppingCart& user) {
    
    // Loads menu and handle all navigation functions 
    char nav = ' ';
    while(nav != 'q') {
        cout << "MENU" << endl;
        cout << "a - Add item to cart" << endl;
        cout << "d - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit" << endl << endl;
        checkInput(nav);
        if(nav == 'a') {
            string itemName;
            string itemDesc;
            int itemPrice;
            int itemQuant;

            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name: " << endl;
            cin.ignore();
            getline(cin, itemName);
            cout << "Enter the item description: " << endl;
            getline(cin, itemDesc);
            cout << "Enter the item price: " << endl; 
            cin >> itemPrice;
            cout << "Enter the item quantity: " << endl;
            cin >> itemQuant;

            ItemToPurchase item(itemName, itemDesc, itemPrice, itemQuant);
            user.addItem(item);
            cout << endl;
        }
        else if(nav == 'd') {
            string itemName;

            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove: " << endl;
            cin.ignore();
            getline(cin, itemName);
            user.removeItem(itemName);
            cout << endl;
        }
        else if(nav == 'c') {
            string itemName;
            int newQuantity;
            ItemToPurchase modItem;

            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name: " << endl;
            cin.ignore();
            getline(cin, itemName);
            modItem.setName(itemName);
            cout << "Enter the new quantity: " << endl;
            cin >> newQuantity;
            modItem.setQuantity(newQuantity);

            user.modifyItem(modItem);
            cout << endl;
        }
        else if(nav == 'i') {
            user.printDescriptions();
            cout << endl;
        }
        else if(nav == 'o') {
            user.printTotal();
            cout << endl;
        }
    }
 }