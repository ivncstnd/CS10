#include <iostream>
#include "IntList.h"
#include "SortedSet.h"

using namespace std;

int main () {
    cout << endl;
    cout << "sset1 constructor called" << endl;
    SortedSet sset1;
    cout << endl;
    cout << "add 50, 29, 100, 1" << endl;
    sset1.add(50);
    sset1.add(29);
    sset1.add(100);
    sset1.add(1);
    cout << "sset1: " << sset1 << endl;
    cout << endl;
    cout << "sset1 destructor called" << endl;
    cout << endl;
    return 0;
}