#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList() {
    head = NULL;
    tail = NULL;
}

IntList::~IntList() {
    IntNode* temp;
    while(head) {
        temp = head; 
        head = head -> next;
        delete temp;
	}
}

void IntList::push_front(int value) {
    IntNode* front = new IntNode(value);
    front -> next = head;
    head = front;
}

void IntList::pop_front() {
    IntNode* front = head;
    head = head -> next;
    delete front;
}

bool IntList::empty() const {
    if(head == NULL) {
        return true;
    }
    return false;
}

const int & IntList::front() const {
    return head->value;
}

const int & IntList::back() const {
    return tail->value;
}

ostream & operator<<(ostream & out, const IntList & list) {
    IntNode* temp = list.head;
    while(temp != NULL) {
        out << temp->value << " ";
        temp = temp->next;
    }
    return out;
}