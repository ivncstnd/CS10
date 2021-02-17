#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList() {
    head = new IntNode(NULL);
    tail = new IntNode(NULL);
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
    if(head == NULL) {
        head = new IntNode(value);
        tail = head;
    }
    else {
        IntNode* temp = new IntNode(value);
        temp->next = head;
        head = temp;
    }
}