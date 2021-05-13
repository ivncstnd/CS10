#include <string>

using namespace std;

#ifndef __NODE_H__
#define __NODE_H__

class Node {
    public:
        Node(string);
        string key;
        Node* left = nullptr;
        Node* right = nullptr;
        Node* parent = nullptr;
        int balFactor = 0;
        int count = 1;
};
#endif