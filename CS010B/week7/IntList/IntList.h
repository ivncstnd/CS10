#ifndef INTLIST_H
#define INTLIST_H

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
        IntList(const IntList &);
        ~IntList();
        void push_front(int);
        void pop_front();
        void push_back(int);
        void clear();
        void selection_sort();
        void insert_ordered(int);
        void remove_duplicates();
        IntList & operator=(const IntList &);
        bool empty() const;
        const int & front() const;
        const int & back() const;
        friend ostream & operator<<(ostream &, const IntList &);
};

#endif