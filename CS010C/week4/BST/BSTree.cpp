#include "BSTree.h"

using namespace std;

BSTree::BSTree() : root(nullptr) 
{}

void BSTree::insert(const string &newString) {
    /* Intializing node with count and key */
    Node* node;
    node->key = newString;
    node->count = 1;
   
    /* If empty, set new node as root */
    if(!root) {
        node->left = nullptr;
        node->right = nullptr;
        node->parent = nullptr;
        root = node;
        return;
    }

    /* Iterating through BST to find placement */
    Node* predNode = nullptr;
    for(Node* currNode = root; !currNode;) {
        predNode = currNode;
        if (node->key > currNode->key) {
            currNode = currNode->right;
        } else if (node->key < currNode->key) {
            currNode = currNode->left;
        } else {
            currNode->count += 1;
            return;
        }
    }

    /* Set node position based on predecessor and link */
    if (node->key > predNode->key) {
        predNode->right = node;
    } else {
        predNode->left = node;
    }
    node->parent = predNode;
}



