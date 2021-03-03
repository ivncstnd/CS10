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
   if(list.head == 0) {
      return out;
   }
   operator<<(out, list.head);
   return out;
}

/* Returns true if the integer passed in is contained within the IntList.
   Otherwise returns false.
*/
bool IntList::exists(int value) const {
   if(head == 0) {
      return false;
   }
   if(head -> value == value) {
      return true;
   }
   return exists(head -> next, value);
}

bool IntList::exists(IntNode *node, int value) const {
   if (node == 0) {
      return false;
   }
   if(node -> value == value) {
      return true;
   }
   return exists(node -> next, value);
}

ostream & operator<<(ostream & out, IntNode * list) {
   if(list == 0) {
      return out;
   }
   out << list -> value;
   if (list -> next != 0) {
      out << " ";
   }
   operator<<(out, list -> next);
   return out;
}