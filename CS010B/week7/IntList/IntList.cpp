#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList() {
    head = NULL;
    tail = NULL;
}

IntList::IntList(const IntList &cpy) {

}

IntList::~IntList() {
    IntNode* i = head;
    while(i) {
        IntNode* node = i; 
        i = i -> next;
        delete node;
    }
    head = NULL;
    tail = NULL;
}

void IntList::push_front(int value) {
    IntNode* front = new IntNode(value);
    front -> next = head;
    head = front;
}

void IntList::pop_front() {
    if(!empty()) {
        IntNode* front = head;
        head = head -> next;
        delete front;
        front = nullptr;
    }
}

void IntList::push_back(int value) {

}

void IntList::clear() {

}

void IntList::selection_sort() {

}

void IntList::insert_ordered(int value) {

}

void IntList::remove_duplicates() {

}

IntList & IntList::operator=(const IntList &rhs) {

}

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
    IntNode* last;
    for(IntNode* i = head; i; i = i -> next) {
        last = i;
    }
    return last -> value;
}

ostream & operator<<(ostream & out, const IntList & list) {
    IntNode* temp = list.head;
    while(temp) {                       
        if(!temp -> next) {             
            out << temp -> value;      
            break;
        }                               
        out << temp -> value << " ";    
        temp = temp -> next;
    }
    return out;
}