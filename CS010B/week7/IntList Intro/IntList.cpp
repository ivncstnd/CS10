#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList() : head(NULL), tail(NULL){
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
    front->next = head;
    head = front;
}

ostream & operator<<(ostream & out, const IntList & list) {
    IntNode* temp = list.head;
    while(temp != NULL) {
        out << temp->value << " ";
        temp = temp->next;
    }
    return out;
}