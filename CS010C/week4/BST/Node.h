#include <string>

using namespace std;

#ifndef __NODE_H__
#define __NODE_H__

class Node {
    public:
        Node(string);
        string key;
        int count = 1;
        Node* left = nullptr;
        Node* right = nullptr;
};
#endif