#include <iostream>
#include "IntList.h"

using namespace std;

/* Constructor */
// Create an empty list by assigning the head and tail as null nodes
IntList::IntList() {
    head = NULL;
    tail = NULL;
}

/* Deconstructor */
// Deleting the list requires going through each element
// and deleting the element, freeing one by one
IntList::~IntList() {
    IntNode* temp;
    while(head) {
        temp = head; 
        head = head -> next;
        delete temp;
	}
}

/* Mutators */
// Pushes a new element to the front of the list
// By creating a new node, the new node will become the head
void IntList::push_front(int value) {
    IntNode* front = new IntNode(value);
    front -> next = head;
    head = front;
}

// Removes the first element from the list
// By assigning the original head to a new node and making the next node
// the head allowing the deletion of the original head
void IntList::pop_front() {
    if(!empty()) {
        IntNode* front = head;
        head = head -> next;
        delete front;
    }
}

/* Accessors */
// Checks if the head node is null
bool IntList::empty() const {
    if(head == NULL) {
        return true;
    }
    return false;
}

// Returns the head node's value
const int & IntList::front() const {
    return head -> value;
}

// Iterates through the list until the tail is found
// if the tail is found, last node is found
// return the value of the last node in the list
const int & IntList::back() const {
    IntNode* last;
    for(IntNode* temp = head; temp != NULL; temp = temp -> next) {
        last = temp;
    }
    return last -> value;
}

// Iterates through the list and outputs the value at the node
// if the tail is found, output the last node's value no whitespace
// and return the list
ostream & operator<<(ostream & out, const IntList & list) {
    IntNode* temp = list.head;
    while(temp != NULL) {
        if(temp -> next == NULL) {
            out << temp -> value;
            break;
        }
        out << temp -> value << " ";
        temp = temp -> next;
    }
    return out;
}