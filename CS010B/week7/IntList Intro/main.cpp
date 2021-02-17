#include <iostream>
#include "IntList.h"
using namespace std;

int main() {
    list = new IntList();
    IntNode* head;
    IntNode* tail = nullptr;
    head = new IntNode(10);
    tail = new IntNode(20);
    list.push_front(head);
    list.push_front(tail);
    
    return 0;
}