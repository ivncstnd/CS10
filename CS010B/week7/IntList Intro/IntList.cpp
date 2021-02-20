#include <iostream>
#include "IntList.h"

using namespace std;

/* Constructor */
// Create an empty list by assigning the head and tail as nullptr nodes
IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

// Creates a copy of using an existing list as a parameter
IntList::IntList(const IntList &cpy) {
    if(!cpy.empty()) {
        IntNode *i = cpy.head; //iterator contains a clone of copy list's value and POINTER.
        IntNode *node = new IntNode(i -> value); //node contains a clone of the copy list's value only.
        head = tail = node; //assign node (copy list's head) to tail which assigns to the new head
        i = i -> next; //iterator points to the next node in the copy list
        while(i) { //while the iterator node is not a nullptr
            node = new IntNode(i -> value);
            i = i -> next;
            tail -> next = node;
            tail = node;
        } //follow standard push_back procedure and iterate to the next node in the copy list
    }
    else {
        head = nullptr;
        tail = nullptr;
    } //checks if the copy list is empty
}

/* Deconstructor */
// Deleting the list requires iterating through each element
// and deleting the element, freeing one by one.
IntList::~IntList() {
    IntNode *i = head;
    while(i) {                  // While the iterator is not nullptr
        head = head -> next;
        delete i;
        i = head;
    }
}

/* Mutators */
// Pushes a new element to the front of the list
void IntList::push_front(int value) {
    if(!head) {
        head = tail = new IntNode(value);
    }
    else {
        IntNode *front = new IntNode(value);
        front -> next = head;
        head = front;
    }
}

// Removes the first element from the list
void IntList::pop_front() {
    if(!empty()) {              // Does nothing if empty
        IntNode *front = head;
        head = head -> next;
        delete front;
        front = nullptr;        // Set the front pointer to nullptr to prevent dangling
    }
}

void IntList::push_back(int value) {
    if(!head) {
        head = tail = new IntNode(value);
    }
    else {
        IntNode *back = new IntNode(value);
        tail -> next = back;
        tail = back;
    }
}

void IntList::clear() {
    if(!this->empty()) {
        this->~IntList();
        head = nullptr;
        tail = nullptr;
    }
}

void IntList::selection_sort() {
    //index node i copies list's head value and pointer
    //i iterates through until it reaches a nullptr
    for(IntNode *i = head; i; i = i -> next) { 
        IntNode *minimumNode = i;   //minimum node copies index's value and pointer
        for(IntNode *j = i; j; j = j -> next) { //index j holds node i's value and pointer, iteratering until nullptr (searches for smallest value)
            if(minimumNode -> value > j -> value) { //if the minimum node's value is greater than index j's value
                minimumNode = j;                    //set the new minimum node to index j
            }
        }
        //finally, swap the values of the original index and the smallest value found 
        IntNode *temp = new IntNode(i -> value);
        i -> value = minimumNode -> value;
        minimumNode -> value = temp -> value;
    }
}

/* Accessors */
// Checks if the head node is nullptr
bool IntList::empty() const {
    if(!head) {                 // If the head is nullptr
        return true;
    }
    return false;
}

// Returns the head node's value
const int & IntList::front() const {
    return head -> value;
}

// return the value of the last node in the list
const int & IntList::back() const {
   return tail -> value;
}

IntList & IntList::operator=(const IntList & rhs) {
    if(this != &rhs) {
        // clear the list 
        this->clear();
        // copy the list 
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

// Iterates through the list and outputs the value at the node
// if the tail is found, output the last node's value no whitespace
// and return the list
ostream & operator<<(ostream & out, const IntList & list) {
    IntNode* temp = list.head;
    while(temp) {                       // While not nullptr
        if(!temp -> next) {             // If the next node is nullptr
            out << temp -> value;       // Last value no space break
            break;
        }                               // Else output node value spaced
        out << temp -> value << " ";    
        temp = temp -> next;
    }
    return out;
}