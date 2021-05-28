#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>

using namespace std;

class Token {
    public:
        string key;
        int frequency = 1;
        Token* left = nullptr;
        Token* right = nullptr;
    public:
        Token(const string &key) : key(key) {}
};

#endif