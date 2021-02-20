#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

/* Node Structure */
// Each node claims 2 blocks of memory allocating:
//    1. A stored integer value
//    2. A pointer address for next node
// The nodes constructor takes in an integer value 
// and automatically assigns the next node as null
// unless otherwise assigned to a new node structure
//        node1           node2
//     | 2 | node2 | -> | 5 | nullptr | 
// Often this data structure is depicted as a staircase
struct IntNode {
    int value;
    IntNode *next;
    IntNode(int value) : value(value), next(nullptr) {}
};

/* Linked List Class */
// A linked list is a data structure with inherent dynamic 
// size flexibility and ease of insertion / deletion
// at the loss of no random access / increased memory usage
class IntList {
// Within a linked list, we allocate a minumum 
// 2 node structure, comprising of the start / end node
    private:
        IntNode* head;
        IntNode* tail;
    public:
        IntList();
        IntList(const IntList &);
        ~IntList();
        void push_front(int);
        void pop_front();
        void push_back(int);
        void clear();
        void selection_sort();
        void insert_ordered(int);
        void remove_duplicates();
        bool empty() const;
        const int & front() const;
        const int & back() const;
        IntList & operator=(const IntList &);
        friend ostream & operator<<(ostream &, const IntList &);
};

#endif