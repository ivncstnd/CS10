#ifndef __HUFFMANTREE_H__
#define __HUFFMANTREE_H__

#include "Token.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HuffmanTree {
    private:
        Token* root;
    public:
        HuffmanTree();
        void addToken(const string &);
        void inOrder() const;
    private:
        void inOrder(Token*) const; 
        Token* addToken(const string &, Token*);
};

#endif