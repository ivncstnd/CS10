#include <iostream>
#include "IntList.h"
using namespace std;

int main() {
    IntList list;
    list.push_front(20);
    list.push_front(19);
    list.push_front(18);
    cout << list << endl;
    return 0;
}