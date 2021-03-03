#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

/* Outputs to a single line all of the int values stored in the list, each separated by a space. 
   This function does NOT output a newline or space at the end.
*/
ostream & operator<<(ostream & out, const IntList & list) {
   if(!list.head) {
      return out;
   }
   operator<<(out, list.head);
   return out;
}

/* Returns true if the integer passed in is contained within the IntList.
   Otherwise returns false.
*/
bool IntList::exists(int value) const {
   if(!head) {
      return false;
   }
   if(head -> value == value) {
      return true;
   }
   return exists(head -> next, value);
}

bool IntList::exists(IntNode *node, int value) const {
   if (!node) {
      return false;
   }
   if(node -> value == value) {
      return true;
   }
   return exists(node -> next, value);
}

ostream & operator<<(ostream & out, IntNode * list) {
   if(!list) {
      return out;
   }
   out << list -> value;
   if (list -> next) {
      out << " ";
   }
   operator<<(out, list -> next);
   return out;
}