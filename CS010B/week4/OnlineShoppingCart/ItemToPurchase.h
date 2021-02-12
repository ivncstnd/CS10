#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

using namespace std;

class ItemToPurchase {
    public: 
        ItemToPurchase();
        ItemToPurchase(string, string, int, int);
        void setName(string);
        void setPrice(int);
        void setQuantity(int);
        void setDescription(string);
        void printItemCost() const;
        void printItemDescription() const;
        string name() const ;
        int price() const;
        int quantity() const;
        string description() const;
    private:
        string _name;
        int _price;
        int _quantity;
        string _description;
};

#endif // end of header