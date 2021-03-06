#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList() : head(nullptr), tail(nullptr) {}

IntList::IntList(const IntList &cpy) {
    head = nullptr;
    tail = nullptr;
    copy(cpy);
}

IntList & IntList::operator=(const IntList &cpy) {
    if(this != &cpy) {
        clear();
        copy(cpy);
    }
    return *this;
}

IntList::~IntList() {
    for(IntNode *i = head; i; i = head -> next) {
        head = head -> next;
        delete i;
    }
}

const int & IntList::front() const {
    return head -> value;
}

const int & IntList::back() const {
    return tail -> value;
}


bool IntList::empty() const {
    if(!head) {
        return true;
    }
    return false;
}

void IntList::push_front(int value) {
    if(empty()) {
        head = tail = new IntNode(value);
    }
    else {
        IntNode *front = new IntNode(value);
        front -> next = head;
        head = front;
    }
}

void IntList::push_back(int value) {
    if(empty()) {
        head = tail = new IntNode(value);
    }
    else {
        IntNode *back = new IntNode(value);
        tail -> next = back;
        tail = back;
    }
}

void IntList::pop_front() {
    if(!empty()) {
        IntNode *front = head;
        head = head -> next;
        delete front;
        front = nullptr;
    }
}

void IntList::selection_sort() {
    for(IntNode *i = head; i; i = i -> next) { 
        IntNode *minimumNode = min(i);
        IntNode *temp = new IntNode(i -> value);
        i -> value = minimumNode -> value;
        minimumNode -> value = temp -> value;
    }
}

void IntList::insert_ordered(int value) {
    if(empty() || value > tail -> value) {
        push_back(value);
    }
    else if(value < tail -> value) {
        push_front(value);
    }
    else {
        for(IntNode *prev = head; prev -> next; prev = prev -> next) {
            if(prev -> next -> value >= value) {
                IntNode *node = new IntNode(value);
                node -> next = prev -> next;
                prev -> next = node;
                return;
            }
        }
    }
}

void IntList::remove_duplicates() {
    for(IntNode *i = head; i && i -> next; i = i -> next) {
        for(IntNode *j = i; j -> next;) {
            if(i -> value == j -> next -> value) {
                IntNode *duplicateNode = j -> next;
                j -> next = j -> next -> next;
                delete(duplicateNode);
            }
            else {
                j = j -> next;
            }
        }
        if(!i -> next) {
            tail = i;
        }
    }
}

ostream & operator<<(ostream &out, const IntList &list) {
    IntNode *i = list.head;
    while(i) {                       // While not nullptr
        if(!i -> next) {             // If the next node is nullptr
            out << i -> value;       // Last value no space break
            return out;
        }                               // Else output node value spaced
        out << i -> value << " ";    
        i = i -> next;
    }
    return out;
}

void IntList::clear() {
    if(!empty()) {
        this->~IntList();
        head = nullptr;
        tail = nullptr;
    }
}

IntNode * IntList::min(IntNode * index) {
    IntNode *minimumNode = index;
    for(IntNode *j = index; j; j = j -> next) {
        if(minimumNode -> value > j -> value) {
            minimumNode = j;
        }
    }
    return minimumNode;
}

void IntList::copy(const IntList &cpy) {
    if(!cpy.empty()) {
        for(IntNode *i = cpy.head; i; i = i -> next) {
            push_back(i -> value);
        }
    }
}

