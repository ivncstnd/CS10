#ifndef __KEY_H__
#define __KEY_H__

#include <string>

using namespace std;

class Key {
    public:
        string token;
        int frequency = 1;
        int code = 1;
    public:
        Key(const string &token) : token(token) {}
};

#endif