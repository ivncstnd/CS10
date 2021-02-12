#include <iostream>
#include "ItemToPurchase.h"

using namespace std;

/* Constructors */
ItemToPurchase::ItemToPurchase() {
    _name = "none";
    _price = 0;
    _quantity = 0;
    _description = "none";
}

ItemToPurchase::ItemToPurchase(string _name, string _description, int _price, int _quantity) {
    this->_name = _name;
    this->_price = _price;
    this->_quantity = _quantity;
    this->_description = _description;
}

/* Mutators */
void ItemToPurchase::setName(string _name) {
    this->_name = _name;
}

void ItemToPurchase::setPrice(int _price) {
    this->_price = _price;
}

void ItemToPurchase::setQuantity(int _quantity) {
    this->_quantity = _quantity;
}

void ItemToPurchase::setDescription(string _description) {
    this->_description = _description;
}

/* Funcs */
void ItemToPurchase::printItemCost() const {
    cout << _name << " " << _quantity << " @ $" << _price << " = $" << _price * _quantity << endl;
}

void ItemToPurchase::printItemDescription() const {
    cout << _description << endl;
}

/* Accessors */
string ItemToPurchase::name() const {
    return _name;
}

int ItemToPurchase::price() const {
    return _price;
}

int ItemToPurchase::quantity() const {
    return _quantity;
 }

 string ItemToPurchase::description() const {
     return _description;
 }



