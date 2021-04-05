#include "IntList.h"
#include <iostream>

using namespace std;

int main() {
    cout << "test case (1-2)" << endl;
    int test;
    cin >> test;
    cout << endl;
    if (test == 1) {
        cout << "list1 constructor called" << endl;
        IntList list1;
        cout << "push front 30" << endl;
        list1.push_front(30);
        cout << "push front 20" << endl;
        list1.push_front(20);
        cout << "push front 10" << endl;
        list1.push_front(10);
        cout << endl;
        cout << "list1: " << list1 << endl;
        cout << endl;
        cout << "list1 reversed: ";
        list1.printReverse();
        cout << endl << endl;
    }
    if (test == 2) {
        cout << "list2 constructor called" << endl;
        IntList list2;
        cout << "pushback 10" << endl;
        list2.push_back(10);
        cout << "pushback 20" << endl;
        list2.push_back(20);
        cout << "pushback 30" << endl;
        list2.push_back(30);
        cout << endl;
        cout << "list2: " << list2 << endl;
        cout << endl;
        cout << "list2 reversed: ";
        list2.printReverse();
        cout << endl << endl;
    }
    return 0;
}