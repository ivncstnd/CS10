#ifndef INTLIST.H
#define INTLIST.h

using namespace std;

/* Node Structure */
// Each node claims 2 blocks of memory allocating:
//    1. A stored integer value
//    2. A pointer address for next node
// The nodes constructor takes in an integer value 
// and automatically assigns the next node as null
// unless otherwise assigned to a new node structure
//         node1                     node2
// |value (2)|ptr (tail)| -> |value (5)|ptr (nullptr)| 
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
        ~IntList();
        void push_front(int value);
        void pop_front();
        bool empty() const;
        const int & front() const;
        const int & back() const;
};

#endif