#include "IntList.h"
#include <iostream>

using namespace std;

int main() {
    IntList list;
    int test;
    cout << "Enter test case: (1-2)" << endl;
    cin >> test;
    cout << endl;
    switch(test) {
        case 1:
            cout << "list1 constructor called" << endl;
            cout << "push front 30" << endl;
            list.push_front(30);
            cout << "push front 20" << endl;
            list.push_front(20);
            cout << "push front 10" << endl;
            list.push_front(10);
            cout << endl;
            cout << "list1: " << list << endl;
            cout << endl;
            cout << "list1 reversed: ";
            list.printReverse();
            cout << endl << endl;
            cout << "pop front" << endl;
            list.pop_front();
            cout << "list1: " << list << endl;
            cout << "pop front" << endl;
            list.pop_front();
            cout << "list1: " << list << endl;
            cout << "pop front" << endl;
            list.pop_front();
            cout << "list1: " << list << endl;
            cout << endl;
            break;
        case 2:
            cout << "list2 constructor called" << endl;
            cout << "pushback 10" << endl;
            list.push_back(10);
            cout << "pushback 20" << endl;
            list.push_back(20);
            cout << "pushback 30" << endl;
            list.push_back(30);
            cout << endl;
            cout << "list2: " << list << endl;
            cout << endl;
            cout << "list2 reversed: ";
            list.printReverse();
            cout << endl << endl;
            cout << "pop back" << endl;
            list.pop_back();
            cout << "list2: " << list << endl;
            cout << "pop back" << endl;
            list.pop_back();
            cout << "list2: " << list << endl;
            cout << "pop back" << endl;
            list.pop_back();
            cout << "list2: " << list << endl;
            cout << endl;
            break;
    }
    return 0;
}