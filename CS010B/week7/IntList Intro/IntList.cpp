#include <iostream>
#include "IntList.h"

using namespace std;

/* Constructor */
// Create an empty list by assigning the head and tail as nullptr nodes (they don't point to anything)
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
    /*
    IntNode *i = head;
    while(i) {// While the iterator is not nullptr
        head = head -> next;
        delete i;
        i = head;
    }
    */
    for(IntNode *i = head; i; i = head -> next) {
        head = head -> next;
        delete i;
    }
}

/* Mutators */
// Pushes a new element to the front of the list
void IntList::push_front(int value) {
    if(empty()) { //if empty, declare a new tail and have the head point to the tail
        head = tail = new IntNode(value);
    }
    else { //else declare a new front node, point the front's pointer to the old head, and assign front the new head
        IntNode *front = new IntNode(value);
        front -> next = head;
        head = front;
    }
}

// Removes the first element from the list
void IntList::pop_front() {
    if(!empty()) { // Does nothing if empty
        IntNode *front = head; //assign a new front node with the current head node
        head = head -> next; //make the new head the next node
        delete front; //delete the old head from the heap
        front = nullptr; //Set the front pointer to nullptr to prevent dangling (doesn't point to anywhere anymore)
    }
}

void IntList::push_back(int value) {
    if(empty()) { //if empty, declare a new tail and have the head point to the tail
        head = tail = new IntNode(value);
    }
    else { //else declare a new back node, point the tail pointer to the new node, and then assign back as the new tail
        IntNode *back = new IntNode(value);
        tail -> next = back;
        tail = back;
    }
}

void IntList::clear() {
    if(!empty()) {
        this->~IntList(); //delete the list
        head = nullptr; //assign the head and tail as nullptr (new list)
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
                minimumNode = j; //set the new minimum node to index j
            }
        }
        //finally, swap the values of the original index and the smallest value found 
        IntNode *temp = new IntNode(i -> value);
        i -> value = minimumNode -> value;
        minimumNode -> value = temp -> value;
    }
}

void IntList::insert_ordered(int value) {
   if(empty()) { //if empty, push back a new value (push front also works)
        push_back(value);
   }
   else { //else
        if(value < head -> value) { //if the value is less than the head, push front the new value
            push_front(value);
        }
        else if(value > tail -> value) { //if the value is greater than the tail, push back the new value
            push_back(value);
        }
        else { //else 
            IntNode *node = new IntNode(value); //assign a new node value with the value given
            IntNode *prevNode = head; //assign the previous node as head (we need a references to reorganize the list)
            while(prevNode -> next) { //while the CURRENT node is not a nullptr
                if(node -> value > prevNode -> next -> value) { //if the value of the new node is greater than the value of the CURRENT node
                    prevNode = prevNode -> next; //proceed
                }
                else { //else
                    node -> next = prevNode -> next; //point the new node to the current node
                    prevNode -> next = node; //point the previous reference node to the new node
                    return; //exit func
                }
            }
        }
    }
}

void IntList::remove_duplicates() {
    IntNode *i = head; //assign index as head
    IntNode *j = nullptr; //declare 2nd index
    IntNode *duplicateNode = nullptr; //declare duplicate node
    while(i && i -> next) { //while index and the next index are not nullptrs
        j = i; //assign the 2nd index to the current index
        while(j -> next) { //while the next 2nd index is not nullptr
            if(i -> value == j -> next -> value) { //check if the value of the stationary index node is the same value of any node on the list
                duplicateNode = j -> next; //if true assign the 2nd indext to the duplicate node,
                j -> next = j -> next -> next; // assign the next to the node after
                delete(duplicateNode); //delete the duplicate
            }
            else { //else proceed
                j = j -> next; 
            }
        }
        i = i -> next; //iterate through entire list
    }
    for(IntNode *i = head; i; i = i -> next) { //readjust the tail
        if(!i->next) {
            tail = i;
        }
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
        clear();
        // copy the list if the rhs list is not empty
        if(!rhs.empty()) {
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
        } //otherwise, return empty
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
            return out;
        }                               // Else output node value spaced
        out << temp -> value << " ";    
        temp = temp -> next;
    }
    return out;
}