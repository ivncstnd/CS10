#include <iostream>
#include "IntList.h"

using namespace std;

/* Constructor */
IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::IntList(const IntList &cpy) {
    if(!cpy.empty()) {
        IntNode *i = cpy.head;
        IntNode *node = new IntNode(i -> value);
        head = tail = node;
        i = i -> next;
        while(i) {
            node = new IntNode(i -> value);
            i = i -> next;
            tail -> next = node;
            tail = node;
        }
    }
    else {
        head = nullptr;
        tail = nullptr;
    } 
}

/* Deconstructor */
IntList::~IntList() {
    IntNode *i = head;
    while(i) {
        head = head -> next;
        delete i;
        i = head;
    }
}

/* Mutators */
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

void IntList::pop_front() {
    if(!empty()) {
        IntNode *front = head;
        head = head -> next;
        delete front;
        front = nullptr;
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

void IntList::clear() {
    if(!empty()) {
        this->~IntList();
        head = nullptr;
        tail = nullptr;
    }
}

void IntList::selection_sort() {
    for(IntNode *i = head; i; i = i -> next) { 
        IntNode *minimumNode = i;
        for(IntNode *j = i; j; j = j -> next) {
            if(minimumNode -> value > j -> value) {
                minimumNode = j;
            }
        }
        IntNode *temp = new IntNode(i -> value);
        i -> value = minimumNode -> value;
        minimumNode -> value = temp -> value;
    }
}

void IntList::insert_ordered(int value) {
   if(empty()) {
        push_back(value);
   }
   else {
        if(value < head -> value) {
            push_front(value);
        }
        else if(value > tail -> value) {
            push_back(value);
        }
        else {
            IntNode *node = new IntNode(value);
            IntNode *prevNode = head;
            while(prevNode -> next) {
                if(node -> value > prevNode -> next -> value) {
                    prevNode = prevNode -> next;
                }
                else {
                    node -> next = prevNode -> next;
                    prevNode -> next = node;
                    return;
                }
            }
        }
    }
}

void IntList::remove_duplicates() {
    IntNode *i = head;
    IntNode *j = nullptr;
    IntNode *duplicateNode = nullptr;
    while(i && i -> next) {
        j = i;
        while(j -> next) {
            if(i -> value == j -> next -> value) {
                duplicateNode = j -> next;
                j -> next = j -> next -> next;
                delete(duplicateNode);
            }
            else {
                j = j -> next;
            }
        }
        i = i -> next;
    }
}

/* Accessors */
bool IntList::empty() const {
    if(!head) {
        return true;
    }
    return false;
}

const int & IntList::front() const {
    return head -> value;
}

const int & IntList::back() const {
   return tail -> value;
}

IntList & IntList::operator=(const IntList & rhs) {
    if(this != &rhs) {
        clear();
        IntNode *i = rhs.head;
        IntNode *node = new IntNode(i -> value);
        head = tail = node;
        i = i -> next;
        while(i) {
            node = new IntNode(i -> value);
            tail -> next = node;
            tail = node;
            i = i -> next;
        } 
    }
    return *this;
}


ostream & operator<<(ostream & out, const IntList & list) {
    IntNode* temp = list.head;
    while(temp) {
        if(!temp -> next) {
            out << temp -> value;
            return out;
        }
        out << temp -> value << " ";    
        temp = temp -> next;
    }
    return out;
}