#include "HuffmanTree.h"

using namespace std;

HuffmanTree::HuffmanTree() : root(nullptr)
{}

void HuffmanTree::addToken(const string &key) {
    root = addToken(key, root);
}

void HuffmanTree::inOrder() const {
    inOrder(root);
}

Token* HuffmanTree::addToken(const string &key, Token* root) {
    if (!root) {
        Token* token = new Token(key);
        return token;
    }

    if(key == root->key) {
        root->frequency += 1;
    } else if (key > root->key) {
        root->right = addToken(key, root->right);
    } else {
        root->left = addToken(key, root->left);
    }

    return root;
}

void HuffmanTree::inOrder(Token* root) const {
    if (!root) {
        return;
    }
    inOrder(root->left);
    cout << root->key << "(" << root->frequency << ") ";
    inOrder(root->right);
}