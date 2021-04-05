#include "IntList.h"

using namespace std;

IntList::IntList() : dummyHead(new IntNode(0)), dummyTail(new IntNode(0)) {
    dummyHead->next = dummyTail;
    dummyHead->prev = nullptr;
    dummyTail->next = nullptr;
    dummyTail->prev = dummyHead;
}

IntList::~IntList() {
    while (dummyHead) {
        IntNode* i = dummyHead;
        dummyHead = dummyHead->next;
        delete i;
    }
    cout << "successfully deleted list" << endl;
}

void IntList::push_front(int value) {
    IntNode* node = new IntNode(value);
    if (empty()) {
        dummyHead->next = node;
        dummyTail->prev = node;
        node->next = dummyTail;
        node->prev = dummyHead;
    } else {
        node->next = dummyHead->next;
        dummyHead->next = node;
        node->next->prev = node;
        node->prev = dummyHead;
    }
}

void IntList::pop_front() {
    if (!empty()) {
        IntNode* node = dummyHead->next;
        dummyHead->next = dummyHead->next->next;
        dummyHead->next->prev = dummyHead;
        delete node;
    }
}

void IntList::push_back(int value) {
    IntNode* node = new IntNode(value);
    if (empty()) {
        dummyHead->next = node;
        dummyTail->prev = node;
        node->next = dummyTail;
        node->prev = dummyHead;
    } else {
        node->prev = dummyTail->prev;
        node->next = dummyTail;
        node->prev->next = node;
        dummyTail->prev = node;
    }
}

void IntList::pop_back() {
    if (!empty()) {
        IntNode* node = dummyTail->prev;
        dummyTail->prev = dummyTail->prev->prev;
        dummyTail->prev->next = dummyTail;
        delete node;
    }
}

bool IntList::empty() const {
    if (dummyHead->next == dummyTail) {
        return true;
    }
    return false;
}

ostream & operator<<(ostream &out, const IntList &rhs) {
    for (IntNode* head = rhs.dummyHead->next; head != rhs.dummyTail; head = head->next) {
        if (head->next == rhs.dummyTail) {
            out << head->data;
            return out;
        }
        out << head->data << " ";
    }
    return out;
}

void IntList::printReverse() const {
    for (IntNode* tail = dummyTail->prev; tail != dummyHead; tail = tail->prev) {
        if (tail->prev == dummyHead) {
            cout << tail->data;
            return;
        }
        cout << tail->data << " ";
    }
}