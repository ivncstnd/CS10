#include <iostream>
#include "IntList.h"

using namespace std;

/* Constructor */
// Create an empty list by assigning the head and tail as null nodes
IntList::IntList() {
    head = NULL;
    tail = NULL;
}

// Creates a copy of using an existing list as a parameter
IntList::IntList(const IntList &cpy) {
    // Stardard list initialization
    // Include a reference node to push front each node from copy list
    head = NULL;
    tail = NULL;
    IntNode *ref = NULL;
    // For each node in the copy list we create a new node to hold the
    // copy node's properties. If the reference node is empty, we assign 
    // the head node. Else the next reference node pointer is pointed 
    // to the new node created  and assign the new node reference to the new node 
    for(IntNode *i = cpy.head; i; i = i -> next) {
        IntNode *node = new IntNode(i -> value);
        if(!ref) {
            head = tail = node;
        } 
        else {
            ref -> next = node;
        }
        ref = node;
    }
    // The loop works similarly to the push_front func
}

/* Deconstructor */
// Deleting the list requires iterating through each element
// and deleting the element, freeing one by one.
IntList::~IntList() {
    IntNode *i = head;
    while(i) {                  // While the iterator is not null
        head = head -> next;
        delete i;
        i = head;
    }
}

/* Mutators */
// Pushes a new element to the front of the list
// By creating a new node, the new node will become the head
void IntList::push_front(int value) {
    if(!head) {
        head = tail = new IntNode(value);
    }
    else {
        IntNode* front = new IntNode(value);
        front -> next = head;
        head = front;
    }
}

// Removes the first element from the list
// By assigning the original head to a new node and making the next node
// the head allowing the deletion of the original head.
void IntList::pop_front() {
    if(!empty()) {              // Does nothing if empty
        IntNode* front = head;
        head = head -> next;
        delete front;
        front = nullptr;        // Set the front pointer to null to prevent dangling
    }
}

/*
void IntList::push_back(int) {

}
*/

/* Accessors */
// Checks if the head node is null
bool IntList::empty() const {
    if(!head) {                 // If the head is null
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
    for(IntNode* i = head; i; i = i -> next) { // Starting from the head and while the iterator is not null
        last = i;                              // Set the iterator as latest value found
    }
    return last -> value;                      // Return value
}

IntList & IntList::operator=(const IntList & rhs) {
    if(this != &rhs) {
        /* free the list */
        this -> ~IntList();
        /* copy the list */
        IntNode *ref = NULL;
        for(IntNode *i = rhs.head; i; i = i -> next) {
            IntNode *node = new IntNode(i -> value);
            if(!ref) {
                head = tail = node;
            } 
            else {
                ref -> next = node;
            }
            ref = node;
        }
    }
    return *this;
}

// Iterates through the list and outputs the value at the node
// if the tail is found, output the last node's value no whitespace
// and return the list
ostream & operator<<(ostream & out, const IntList & list) {
    IntNode* temp = list.head;
    while(temp) {                       // While not null
        if(!temp -> next) {             // If the next node is null
            out << temp -> value;       // Last value no space break
            break;
        }                               // Else output node value spaced
        out << temp -> value << " ";    
        temp = temp -> next;
    }
    return out;
}