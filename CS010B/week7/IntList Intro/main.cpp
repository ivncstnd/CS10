#include <iostream>
#include "IntList.h"
using namespace std;

int main() {
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
        cout << endl;
        cout << "Calling list1 destructor..." << endl;
    }
    cout << "list1 destructor returned" << endl;

    {
        cout << "\nlist2 constructor called" << endl;
        IntList list2;
        if (list2.empty()) 
            cout << "list2 is empty" << endl;
        cout << "\nCalling list2 destructor..." << endl;
   }
   cout << "list2 destructor returned" << endl;
    return 0;
}