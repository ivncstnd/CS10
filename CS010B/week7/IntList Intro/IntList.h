#ifndef INTLIST.H
#define INTLIST.h

using namespace std;

struct IntNode {
    int value;
    IntNode *next;
    IntNode(int value) : value(value), next(nullptr) {}
};

class IntList {
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