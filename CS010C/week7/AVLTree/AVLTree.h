#include "Node.h"

using namespace std;

#ifndef __AVLTREE_H__
#define __AVLTREE_H__

class AVLTree {
    private:
        Node* root;
    public:
        //mutators
        AVLTree();
        void insert(const string &newString);

        //accessors
        int height(const string&) const;
        int balanceFactor(Node*);
        bool search(const string &key) const;

        //printers
        void printBalanceFactors(); //new
        void visualizeTree(const string &); //given

      private:
        //new
		Node* findUnbalancedNode(Node*);//done
		Node* rotateLeft(Node*);//done
		Node* rotateRight(Node*);//done
		void printBalanceFactors(Node*);
		void visualizeTree(ofstream&, Node*);//given
        void rebalance(Node*); //done
		void setBalanceFactors(Node*); //done

        //old
         Node* insert(const string &newString, Node* root);
         int height(Node* root) const;
         Node* search(const string &key, Node* root) const;
};

#endif // __AVLTREE_H__