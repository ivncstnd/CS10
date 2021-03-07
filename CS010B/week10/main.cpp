#include <iostream>
#include "IntList.h"
#include "SortedSet.h"

using namespace std;

int main () {
    int test;
    cout << "enter test between 1-?" << endl;
    cin >> test;
    if(test == 1) {
        cout << endl;
        cout << "sset1 constructor called" << endl;
        SortedSet sset1;
        cout << endl;
        cout << "add 2, 5, 9" << endl;
        sset1.add(2);
        sset1.add(5);
        sset1.add(9);
        cout << "sset1: " << sset1 << endl;
        cout << endl;
        cout << "add case: 2, 1, 4, 7, 5, 9, 11" << endl;
        sset1.add(2);
        sset1.add(1);
        sset1.add(4);
        sset1.add(7);
        sset1.add(5);
        sset1.add(9);
        sset1.add(11);
        cout << "sset1: " << sset1 << endl;
        cout << endl;
        cout << "push_front, push_back case: 1, 0, 11, 12" << endl;
        sset1.push_front(1);
        sset1.push_front(0);
        sset1.push_back(11);
        sset1.push_back(12);
        cout << "sset1: " << sset1 << endl;
        cout << endl;
        cout << "in set case: 0, 4, 8, 12" << endl;
        for(int i = 0; i <= 12; i += 4) {
            if(sset1.in(i)) {
                cout << i << " is present in set" << endl;
            }
            else {
                cout << i << " is not present in set" << endl;
            }
        }
        cout << endl;
        cout << "sset1 destructor called" << endl;
        cout << endl;
    }
    if(test == 2) {
        cout << endl;
        cout << "sset2 constructor called && add: 0, 5, 9" << endl;
        SortedSet sset2;
        sset2.add(0);
        sset2.add(5);
        sset2.add(9);
        cout << "sset3 constructor called && add: 0, 2, 9, 11" << endl;
        SortedSet sset3;
        sset3.add(0);
        sset3.add(2);
        sset3.add(9);
        sset3.add(11);
        cout << endl;
        cout << "sset2: " << sset2 << endl;
        cout << "sset3: " << sset3 << endl;
        cout << endl;
        cout << "sset2 & sset3: " << (sset2 & sset3) << endl;
        cout << endl;
        cout << "sset4 constructor called && sset4 = sset2 & sset3" << endl;
        SortedSet sset4;
        sset4 = sset2 & sset3;
        cout << "sset4: " << sset4 << endl; 
        cout << endl;
        cout << "sset2 | sset3: " << (sset2 | sset3) << endl;
        cout << endl;
        cout << "sset5 constructor called && sset5 = sset2 | sset3" << endl;
        SortedSet sset5;
        sset5 = sset2 | sset3;
        cout << "sset5: " << sset5 << endl;
        cout << endl;
        cout << "sset2, sset3, sset4 destructor called" << endl;
        cout << endl;
    }
    return 0;
}