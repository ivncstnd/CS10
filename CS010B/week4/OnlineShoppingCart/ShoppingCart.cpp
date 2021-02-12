#include <iostream>
#include <vector>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

/* Constructors */
ShoppingCart::ShoppingCart() {
    _customerName = "none";
    _currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string _customerName, string _currentDate) {
    this->_customerName = _customerName;
    this->_currentDate = _currentDate;
}

/* Funcs */
void ShoppingCart::addItem(ItemToPurchase newItem) {
    _cartItems.push_back(newItem);
}

void ShoppingCart::removeItem(string remItem) {
    bool removed = false;
    for(unsigned i = 0; i < _cartItems.size(); ++i) {
        if(remItem == _cartItems.at(i).name()) {
            _cartItems.erase(_cartItems.begin()+i);
            removed = true;
        }
    }
    if(!removed) {
        cout <<  "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::modifyItem(ItemToPurchase modItem) {
    bool modified = false;
    for(unsigned i = 0; i < _cartItems.size(); ++i) {
        if(modItem.name() == _cartItems.at(i).name()) {
            if(modItem.price() != 0) {
                _cartItems.at(i).setPrice(modItem.price());
            }
            if(modItem.quantity() != 0) {
                _cartItems.at(i).setQuantity(modItem.quantity());
            }
            if(modItem.description() != "none") {
                _cartItems.at(i).setDescription(modItem.description());
            }
            modified = true;
        }
    }
    if(!modified) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

int ShoppingCart::numItemsInCart() const {
    int totalItems = 0;
    for (unsigned i = 0; i < _cartItems.size(); ++i) {
        totalItems += _cartItems.at(i).quantity();
    }
    return totalItems;
}

int ShoppingCart::costOfCart() const {
    int totalCost = 0;
    for(unsigned i = 0; i < _cartItems.size(); ++i) {
        totalCost += _cartItems.at(i).price() * _cartItems.at(i).quantity();
    }
    return totalCost;
}

void ShoppingCart::printTotal() const {
    cout << "\nOUTPUT SHOPPING CART" << endl; 
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << "Number of Items: " << numItemsInCart() << endl;
    cout << endl;
    if(_cartItems.size() != 0) {
        for(unsigned i = 0; i < _cartItems.size(); ++i) {
            _cartItems.at(i).printItemCost();
        }
    }
    else {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    cout << endl;
    cout << "Total: $" << costOfCart() << endl;
}

void ShoppingCart::printDescriptions() const {
    cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << endl << "Item Descriptions" << endl;
    for(unsigned i = 0; i < _cartItems.size(); ++i) {
        cout << _cartItems.at(i).name() << ": ";
        _cartItems.at(i).printItemDescription();
    }
}

/* Accessors */
string ShoppingCart::customerName() const {
    return _customerName;
}

string ShoppingCart::date() const {
    return _currentDate;
}