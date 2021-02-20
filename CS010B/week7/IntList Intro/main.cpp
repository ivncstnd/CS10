#include <iostream>
#include "IntList.h"
using namespace std;

int main() {
    /*
    {
        cout << "\nlist1 constructor called" << endl;
        IntList list1;
        cout << "pushfront 10" << endl;
        list1.push_front(10);
        cout << "pushfront 20" << endl;
        list1.push_front(20);
        cout << "pushfront 30" << endl;
        list1.push_front(30);
        cout << "list1: " << list1 << endl;
        cout << "pop" << endl;
        list1.pop_front();
        cout << "list1: " << list1 << endl;
        cout << "pop" << endl;
        list1.pop_front();
        cout << "list1: " << list1 << endl;
        cout << "pop" << endl;
        list1.pop_front();
        cout << "list1: " << list1 << endl;
        cout << "pushfront 100" << endl;
        list1.push_front(100);
        cout << "pushfront 200" << endl;
        list1.push_front(200);
        cout << "pushfront 300" << endl;
        list1.push_front(300);
        cout << "list1: " << list1 << endl;
        cout << "list1 front: " << list1.front() << endl;
        cout << "list1 back: " << list1.back() << endl;
        IntList list3(list1);
        cout << "list3: " << list3 << endl;
        cout << "pushfront 400" << endl;
        list3.push_front(400);
        cout << "list3: " << list3 << endl;
        cout << "list1: " << list1 << endl;
        cout << endl;
        cout << "Calling list1 & list3 destructor..." << endl;
        
    }
    cout << "list1 & list3 destructor returned" << endl;

    {
        cout << "\nlist2 constructor called" << endl;
        IntList list2;
        if (list2.empty()) 
            cout << "list2 is empty" << endl;
        cout << "\nCalling list2 destructor..." << endl;
   }
   cout << "list2 destructor returned" << endl;
   */
    /*
    cout << "\nlist1 constructor called" << endl;
    IntList list1;
    list1.push_front(1);
    list1.push_front(2);
    cout << "list1: " << list1 << endl;
    cout << "\nlist2 constructor called" << endl;
    IntList list2;
    cout << "list2 = list1" << endl;
    list2 = list1;
    cout << "list2: " << list2 << endl;
    list2.push_front(1);
    list2.push_front(2);
    cout << "list2: " << list2 << endl;
    cout << "list1 = list2" << endl;
    list1 = list2;
    cout << "list1: " << list1 << endl;
    list1.push_front(3);
    list1.push_back(4);
    cout << "list1: " << list1 << endl;
    */
   /*
    cout << "\nlist1 constructor called" << endl;
    IntList list1;
    cout << "list 1 push front two nodes" << endl;
    list1.push_front(2);
    list1.push_front(1);
    cout << "list1: " << list1 << endl;
    cout << "list1 push back" << endl;
    list1.push_back(3);
    cout << "list1: " << list1 << endl;
    cout << "list1 push front / back" << endl;
    list1.push_front(0);
    list1.push_back(4);
    cout << "list1: " << list1 << endl;
    cout << "\nlist2 constructor called" << endl;
    IntList list2;
    list2.push_front(-1);
    list2.push_back(5);
    cout << "list2: " << list2 << endl;
    cout << "list2 = list1" << endl;
    list2 = list1;
    cout << "list2: " << list2 << endl;
    cout << "list2 push front / back" << endl;
    list2.push_front(-1);
    list2.push_back(5);
    cout << "list2: " << list2 << endl;
    cout << "list1: " << list1 << endl;
    */

   /*
    cout << "\nlist1 constructor called" << endl;
    IntList list1;
    cout << "\nlist2 constructor called" << endl;
    IntList list2(list1);
    cout << "list2: " << list2 << endl;
    cout << "list1: " << list1 << endl;
    */
   
    /*
    cout << "\nlist1 constructor called" << endl;
    IntList list1;
    list1.push_front(0);
    list1.push_front(5);
    list1.push_front(20);
    list1.push_back(50);
    cout << "list1: " << list1 << endl;
    cout << "\nlist1 clear called" << endl;
    list1.clear();
    if(list1.empty()) {
        cout << "list1 is empty" << endl;
    }
    cout << "list1: " << list1 << endl;
    list1.push_front(0);
    list1.push_front(5);
    list1.push_front(20);
    list1.push_back(50);
    cout << "list1: " << list1 << endl;
    cout << "\nlist1 clear called" << endl;
    list1.clear();
    if(list1.empty()) {
        cout << "list1 is empty" << endl;
    }
    cout << "\nlist1 clear called" << endl;
    list1.clear();
    if(list1.empty()) {
        cout << "list1 is empty" << endl;
    }
    */

   /*
    cout << "\nlist1 constructor called" << endl;
    IntList list1;
    //list1.insert_ordered(6);
    //cout << "list1: " << list1 << endl;
    list1.push_front(0);
    list1.push_back(5);
    cout << "list1: " << list1 << endl;
    list1.insert_ordered(1);
    list1.insert_ordered(-1);
    list1.insert_ordered(7);
    list1.insert_ordered(12);
    cout << "list1: " << list1 << endl;
    list1.insert_ordered(6);
    cout << "list1: " << list1 << endl;
    list1.insert_ordered(2);
    cout << "list1: " << list1 << endl;
    IntList list2;
    cout << "list2 = list1" << endl;
    list2 = list1;
    cout << "\nlist1 clear called" << endl;
    list1.clear();
    if(list1.empty()) {
        cout << "list1 is empty" << endl;
    }
    cout << "\nlist1 clear called" << endl;
    list1.clear();
    if(list1.empty()) {
        cout << "list1 is empty" << endl;
    }
    cout << "list1: " << list1 << endl;
    cout << "list2: " << list2 << endl;
    */
    /*
    cout << "\nlist1 constructor called" << endl;
    IntList list1;
    list1.push_back(5);
    list1.push_back(1);
    list1.push_back(1);
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(4);
    cout << "list1: " << list1 << endl;
    list1.remove_duplicates();
    cout << "list1: " << list1 << endl;
    */
   
       cout << "Enter a test number(1-5): ";
	int test;
	cin >> test;
	cout << endl;
   //tests constructor, destructor, push_front, pop_front, display
   if (test == 1) {
      cout << endl;
      cout << "list1 constructor called" << endl;
      IntList list1;
      cout << "pushfront 10" << endl;
      list1.push_front(10);
      cout << "pushfront 20" << endl;
      list1.push_front(20);
      cout << "pushfront 30" << endl;
      list1.push_front(30);
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
   }
   if (test == 1) {
      cout << "list1 destructor called" << endl;
   }

   //tests push_back
   if (test == 2) {
      cout << endl;
      cout << "list2 constructor called" << endl;
      IntList list2;
      cout << "pushback 10" << endl;
      list2.push_back(10);
      cout << "pushback 20" << endl;
      list2.push_back(20);
      cout << "pushback 30" << endl;
      list2.push_back(30);
      cout << "list2: " << list2 << endl;
      cout << "pop" << endl;
      list2.pop_front();
      cout << "list2: " << list2 << endl;
      cout << "pop" << endl;
      list2.pop_front();
      cout << "list2: " << list2 << endl;
      cout << "pop" << endl;
      list2.pop_front();
      cout << "list2: " << list2 << endl;
   }
   if (test == 2) {
      cout << "list2 destructor called" << endl;
   }

   //tests selection_sort
   if (test == 3) {
      cout << endl;
      cout << "list3 constructor called" << endl;
      IntList list3;
      cout << "pushfront 10" << endl;
      list3.push_front(10);
      cout << "pushfront 20" << endl;
      list3.push_front(20);
      cout << "pushfront 30" << endl;
      list3.push_front(30);
      cout << "list3: " << list3 << endl;
      cout << "selection_sort()" << endl;
      list3.selection_sort();
      cout << "list3: " << list3 << endl;
      cout << "pop" << endl;
      list3.pop_front();
      cout << "pop" << endl;
      list3.pop_front();
      cout << "pop" << endl;
      list3.pop_front();
      cout << "list3: " << list3 << endl;
      cout << "selection_sort()" << endl;
      list3.selection_sort();
      cout << "list3: " << list3 << endl;
      cout << "pushfront 10" << endl;
      list3.push_front(10);
      cout << "selection_sort()" << endl;
      list3.selection_sort();
      cout << "list3: " << list3 << endl;
      cout << "pushfront 20" << endl;
      list3.push_front(20);
      cout << "list3: " << list3 << endl;
      cout << "selection_sort()" << endl;
      list3.selection_sort();
      cout << "list3: " << list3 << endl;
   }
   if (test == 3) {
      cout << "list3 destructor called" << endl;
   }

   //tests insert_sorted
   if (test == 4) {
      cout << endl;
      cout << "list4 constructor called" << endl;
      IntList list4;
      cout << "insert 20" << endl;
      list4.insert_ordered(20);
      cout << "insert 10" << endl;
      list4.insert_ordered(10);
      cout << "insert 30" << endl;
      list4.insert_ordered(30);
      cout << "list4: " << list4 << endl;
      cout << "insert 50" << endl;
      list4.insert_ordered(50);
      cout << "list4: " << list4 << endl;
      cout << "insert 40" << endl;
      list4.insert_ordered(40);
      cout << "list4: " << list4 << endl;
      cout << "insert 11" << endl;
      list4.insert_ordered(11);
      cout << "list4: " << list4 << endl;
      cout << "insert 10" << endl;
      list4.insert_ordered(10);
      cout << "list4: " << list4 << endl;
      cout << "insert 11" << endl;
      list4.insert_ordered(11);
      cout << "list4: " << list4 << endl;
      cout << "insert 9" << endl;
      list4.insert_ordered(9);
      cout << "list4: " << list4 << endl;
      cout << "insert 50" << endl;
      list4.insert_ordered(50);
      cout << "list4: " << list4 << endl;
      cout << "insert 51" << endl;
      list4.insert_ordered(51);
      cout << "list4: " << list4 << endl;
   }
   if (test == 4) {
      cout << "list4 destructor called" << endl;
   }
   
   //tests remove_duplicates
   if (test == 5) {
      cout << endl;
      cout << "list5 constructor called" << endl;
      IntList list5;
      cout << "pushfront 10" << endl;
      list5.push_front(10);
      cout << "pushfront 20" << endl;
      list5.push_front(20);
      cout << "pushfront 10" << endl;
      list5.push_front(10);
      cout << "pushfront 30" << endl;
      list5.push_front(30);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pushfront 10" << endl;
      list5.push_front(10);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pushfront 20" << endl;
      list5.push_front(20);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pushfront 20" << endl;
      list5.push_front(20);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pushfront 20" << endl;
      list5.push_front(20);
      cout << "pushfront 20" << endl;
      list5.push_front(20);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pop" << endl;
      list5.pop_front();
      cout << "pop" << endl;
      list5.pop_front();
      cout << "push_front(30)" << endl;
      list5.push_front(30);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "push_front(30)" << endl;
      list5.push_front(30);
      cout << "push_front(30)" << endl;
      list5.push_front(30);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pop" << endl;
      list5.pop_front();
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
   }
   if (test == 5) {
      cout << "list5 destructor called" << endl;
   }

   if(test == 6) {
      cout << endl;
      cout << "list6 constructor called" << endl;
      IntList list6;
      cout << "pushfront 10" << endl;
      list6.push_front(10);
      cout << "pushfront 20" << endl;
      list6.push_front(20);
      cout << "pushfront 10" << endl;
      list6.push_front(10);
      cout << "pushfront 30" << endl;
      list6.push_front(30);
      cout << "list6: " << list6 << endl;
      cout << endl;
      cout << "list7 constructor called" << endl;
      IntList list7;
      cout << "list7 = list6" << endl;
      list7 = list6;
      cout << "list7: " << list7 << endl;
      cout << endl;
      cout << "clearing list6 & list7" << endl;
      list6.clear();
      list7.clear();
      cout << "list7 = list6" << endl;
      list7 = list6;
      cout << "list 6: " << list6 << endl;
      cout << "list 7: " << list7 << endl;
      cout << endl;
   }
   if(test == 6) {
      cout << "list6 destructor called" << endl;
   }

   if(test == 7) {
      cout << endl;
      cout << "list8 constructor called" << endl;
      IntList list8;
      cout << "list8 push front 5 nodes" << endl;
      list8.push_front(1);
      list8.push_front(1);
      list8.push_front(5);
      list8.push_front(1);
      list8.push_front(3);
      cout << "list8: " << list8 << endl;
      cout << "remove duplicates" << endl;
      list8.remove_duplicates();
      cout << "list8: " << list8 << endl;
      cout << "list8 back: " << list8.back() << endl;
      cout << endl; 
      list8.push_front(5);
      list8.push_front(5);
      cout << "list8: " << list8 << endl;
      cout << "remove duplicates" << endl;
      list8.remove_duplicates();
      cout << "list8: " << list8 << endl;
      cout << "list8 back: " << list8.back() << endl;
      cout << endl; 
   }
   if(test == 7) {
      cout << "list8 destructor called" << endl;
   }
   /*
    IntList list1;
    list1.remove_duplicates();
    list1.back();
    list1.front();
    list1.pop_front();
    list1.pop_front();
    cout << list1 << endl;
    */
   
   /*
   * Destructor will be tested by looking at code. There is no run-time 
   * test for it. Make sure your destructor actually deletes ALL nodes, not
   * just the head and/or tail.
   */

  /*
   IntList list1;
   IntList list2;
   list1 = list2;
   cout << "list1 = list2: " << list1 << endl;
   */
    return 0;
}