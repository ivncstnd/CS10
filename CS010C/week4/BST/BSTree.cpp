#include "BSTree.h"
#include "Node.h"
#include <iostream>

using namespace std;

/* Constructor */
BSTree::BSTree() : root(nullptr) 
{}

/* Recursive function */
void BSTree::insert(const string &newString) {
    root = insert(newString, root);
}

void BSTree::remove(const string &key) {
    root = remove(key, root);
}

bool BSTree::search(const string &key) const {
    Node* node = search(key, root);
    if (node) {
        return true;
    }
    return false;
}

string BSTree::largest() const {
    Node* largest = rightMostNode(root);
    if (largest) {
        return largest->key;
    }
    return "";
}

string BSTree::smallest() const {
    Node* smallest = leftMostNode(root);
    if (smallest) {
        return smallest->key;
    }
    return "";
}

int BSTree::height(const string &key) const {
    Node* node = search(key, root);
    return height(node);
}

void BSTree::preOrder() const {
    preOrder(root);
}

void BSTree::postOrder() const {
    postOrder(root);
}

void BSTree::inOrder() const {
    inOrder(root);
}





/* Helper functions */
Node* BSTree::insert(const string &newString, Node* root) {
    // Create a new node if current node is nullptr
    if (!root) {
        Node* newNode = new Node(newString);
        return newNode;
    }
    // Otherwise, check string with current node and branch
    if (newString == root->key) {
        root->count += 1;
    /* NOTE: ASCII characters range from int 65 - 90 (A - Z) and 97 - 122 (a - z)
     * therefore z > char > a > Z > char > A , thus effecting ordering making
     * earlier letters / uppercase on the alphabet left-skewed and latter letters right-skewed.
     */
    } else if (newString > root->key) {
        root->right = insert(newString, root->right);
    } else {
        root->left = insert(newString, root->left);
    }
    
    return root;
}

// given a key, delete the key from the tree and return a new tree root
Node* BSTree::remove(const string &key, Node* root) {
    // if it doesn't exist return
    if (!root) {
        return root;
    }

    // directional movement based on key
    if (key > root->key) {
        root->right = remove(key, root->right);
    } else if (key < root->key) {
        root->left = remove(key, root->left);
    // key found, to be deleted
    } else {
        // if the count is greater than 1, dec and return
        if (root->count > 1) {
            root->count -= 1;
            return root;
        }
        
        // if node has no left child
        if (!root->left) {
            // however a right child exists
            if (root->right) {
                // grab the smallest key from the right subtree (in-order successor)
                Node* temp = leftMostNode(root->right);
                // set the new key to the old position
                root->key = temp->key;
                root->count = temp->count;
                temp->count = 1;
                // delete the successor
                root->right = remove(temp->key, root->right);
            // else delete leaf
            } else {
                Node* temp = root->left;
                delete root;
                return temp;
            }
        } else {
            // grab the largest key from the left subtree (in-order predecessor)
            Node *temp = rightMostNode(root->left);
            // set the new key to the old position
            root->key = temp->key;
            root->count = temp->count;
            temp->count = 1;
            // delete the predecessor
            root->left = remove(temp->key, root->left);
        }
    }
    return root;
}

Node* BSTree::search(const string &key, Node* root) const {
    if (!root || root->key == key) {
        return root;
    }
    if (root->key < key) {
        return search(key, root->right);
    } else {
        return search(key, root->left);
    }
}

int BSTree::height(Node* root) const {
    if (!root) {
        return -1;
    } else if (!root->left && !root->right) {
        return 0;
    }
    int LH = height(root->left);
    int RH = height(root->right);
    if (LH > RH) {
        return LH + 1;
    } else {
        return RH + 1;
    }
    return 0;
}

/* Tree transversal prints*/

/* Outputs on first visited (Root, Left, Right)
 * Inorder to print correctly, the current node is compared to the
 * deepest node in the tree and if true, prints the last node and 
 * creates a newline.
 */
void BSTree::preOrder(Node* root) const {
    if (!root) {
        return;
    }
    cout << root->key << "(" << root->count << "), ";
    preOrder(root->left);
    preOrder(root->right);
}

/* Outputs on final visit
 * Inorder to print correctly, the current node is compared to the
 * tree's root node, as it is the last output in a post order transversal.
 */
void BSTree::postOrder(Node* root) const {
    if (!root) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->key << "(" << root->count << "), ";
}

/* Outputs on 2nd visit
 * Inorder to print correctly, the current node is compared to the
 * tree's far most right node, as it is the last output in an in order transversal.
 */
void BSTree::inOrder(Node* root) const {
    if (!root) {
        return;
    }
    inOrder(root->left);
    cout << root->key << "(" << root->count << "), ";
    inOrder(root->right);
}

/* Helper functions to aid tranversal prints */
Node* BSTree::rightMostNode(Node* root) const {
    if (root) {
        Node *i = root;
        for (; i->right; i = i->right);
        return i;
    }
    return nullptr;
}

Node* BSTree::leftMostNode(Node* root) const {
    if (root) {
        Node *i = root;
        for(; i->left; i = i->left);
        return i;
    }
    return nullptr;
}
