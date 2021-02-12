#ifndef SHOPPINGCART_H 
#define SHOPPINGCART_H

#include <iostream>
#include <vector>
#include "ItemToPurchase.h"

using namespace std;

class ShoppingCart {
    public:
        ShoppingCart();
        ShoppingCart(string, string);
        void addItem(ItemToPurchase);
        void removeItem(string);
        void modifyItem(ItemToPurchase);
        int numItemsInCart() const;
        int costOfCart() const;
        void printTotal() const;
        void printDescriptions() const;
        string customerName() const;
        string date() const;
    private:
        string _customerName;
        string _currentDate;
        vector<ItemToPurchase> _cartItems;
};

#endif  //end of header