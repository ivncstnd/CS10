#include "SortedSet.h"
#include <iostream>

using namespace std;

SortedSet::SortedSet() : IntList() {}

SortedSet::SortedSet(const SortedSet & cpy) : IntList(cpy) {}

SortedSet::SortedSet(const IntList & cpy) : IntList(cpy) {
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet() {}

bool SortedSet::in(int value) const {
    for(IntNode *i = head; i; i = i -> next) {
        if(value == i -> value) {
            return true;
        }
    }
    return false;
}

SortedSet SortedSet::operator|(const SortedSet &set) {
    SortedSet newSet;
    if(set.head) {
        for(IntNode *i = set.head; i; i = i -> next) {
            newSet.add(i -> value);
        }
    }
    if(head) {
        for(IntNode *i = head; i; i = i -> next) {
            newSet.add(i -> value);
        }
    }
    return newSet;
}

SortedSet SortedSet::operator&(const SortedSet &set) {
    SortedSet newSet;
    if(set.head) {
        for(IntNode *i = set.head; i; i = i -> next) {
            if(in(i -> value)) {
                newSet.add(i -> value);
            }
        }
    }
    return newSet;
}

void SortedSet::add(int value) {
    if(!head) {
        head = tail = new IntNode(value);
    }
    else if(value < head -> value) {
        IntNode *front = new IntNode(value);
        front -> next = head;
        head = front;
    }
    else if(value > tail -> value) {
        IntNode *back = new IntNode(value);
        tail -> next = back;
        tail = back;
    }
    else {
        for(IntNode *i = head; i; i = i -> next) {
            if(value == i -> value) {
                return;
            }
            if(i -> next -> value > value) {
                IntNode *node = new IntNode(value);
                node -> next = i -> next;
                i -> next = node;
                return;
            }
        }
    }
}

void SortedSet::push_front(int value) {
    add(value);
}

void SortedSet::push_back(int value) {
    add(value);
}

void SortedSet::insert_ordered(int value) {
    add(value);
}

SortedSet SortedSet::operator|=(const SortedSet &set) {
    SortedSet newSet = operator|(set);
    return *this = newSet;
}

SortedSet SortedSet::operator&=(const SortedSet &set) {
    SortedSet newSet = operator&(set);
    return *this = newSet;
}
