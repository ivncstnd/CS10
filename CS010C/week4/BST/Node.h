#include <string>

using namespace std;

#ifndef __NODE_H__
#define __NODE_H__

class Node {
    public:
        string key;
        int count;
        Node* left;
        Node* right;
        Node* parent;
};
#endif