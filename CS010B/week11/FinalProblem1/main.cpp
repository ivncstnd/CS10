/**
 * The goal of this problem is to extend the IntList class to add an additional function, largestToTail(). 
 * This function does not return anything and moves the Node with the largest value to the tail end of the list, keeping all other Nodes in the same relative order.
 * For example, given largestToTail() is called on the following IntList
 * 
 * 17 -> 32 -> 99 -> 43 -> 11 -> 42
 * the IntList after the call should be
 * 17 -> 32 -> 43 -> 11 -> 42 -> 99
 * 
 * Be sure to NOT leave any DANGLING POINTERS or MEMORY LEAKS!
 * Note that the IntNode class we are using in this program is slightly different from the one you have used for the previous labs and programs. 
 * The value field of the IntNode is declared const, which means that you cannot assign or modify the value of a node after it is created.
 */

#include <iostream>
#include "IntList.h"

using namespace std;

int main() {
  cout << "Enter a test case #: ";
  int testCase;
  cin >> testCase;
  cout << endl;

  if (testCase == 0) {
    IntList il;
    il.push_front(7);
    il.push_front(4);
    il.push_front(9);
    il.push_front(6);
    il.push_front(5);
    cout << "Before: " << il << endl;
    il.largestToTail();
    cout << "After: " << il << endl;
  } else if (testCase == 1) {
    IntList il;
    il.push_front(2);
    il.push_front(7);
    il.push_front(1);
    il.push_front(4);
    il.push_front(9);
    il.push_front(3);
    cout << "Before: " << il << endl;
    il.largestToTail();
    cout << "After: " << il << endl;
  } else if (testCase == 2) {
    IntList il;
    il.push_front(12);
    il.push_front(9);
    il.push_front(-1);
    il.push_front(4);
    il.push_front(7);
    il.push_front(3);
    cout << "Before: " << il << endl;
    il.largestToTail();
    cout << "After: " << il << endl;
  } else if (testCase == 3) {
    IntList il;
    il.push_front(-5);
    il.push_front(-4);
    il.push_front(-3);
    il.push_front(-2);
    il.push_front(-1);
    cout << "Before: " << il << endl;
    il.largestToTail();
    cout << "After: " << il << endl;
  } else if (testCase == 4) {
    IntList il;
    il.push_front(-2);
    il.push_front(1);
    cout << "Before: " << il << endl;
    il.largestToTail();
    cout << "After: " << il << endl;
  } else if (testCase == 5) {
    IntList il;
    il.push_front(9);
    cout << "Before: " << il << endl;
    il.largestToTail();
    cout << "After: " << il << endl; 
  } else if (testCase == 6) {
    IntList il;
    cout << "Before: " << il << endl;
    il.largestToTail();
    cout << "After: " << il << endl; 
  }
}
