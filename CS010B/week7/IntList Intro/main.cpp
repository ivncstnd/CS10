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
    return 0;
}