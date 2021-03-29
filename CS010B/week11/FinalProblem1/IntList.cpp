#include "IntList.h"

/* Initializes an empty list.
*/
IntList::IntList() : head(nullptr) {}

/* Inserts a data value to the front of the list.
*/
void IntList::push_front(int val) {
  if (!head) {
    head = new IntNode(val);
  } else {
    IntNode *temp = new IntNode(val);
    temp->next = head;
    head = temp;
  }
}

void IntList::largestToTail() {
   if(head && head -> next) {
      IntNode *max = head ;
      for (IntNode *i = head; i; i = i -> next) {
         if(i -> value > max -> value) {
            max = i;   
         }
      }
      for (IntNode *i = head; i; i = i -> next) {
         if(max == head) {
            head = head -> next;
         }
         else if(max == i -> next) {
            i -> next = i -> next -> next;
         }
         if(!i -> next) {
            i -> next = max;
            max -> next = nullptr;
         }
      }
   }
}