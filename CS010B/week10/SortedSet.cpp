#include "SortedSet.h"
#include <iostream>

using namespace std;

SortedSet::SortedSet() : IntList() {}

SortedSet::SortedSet(const SortedSet & cpy) : IntList(cpy) {}

SortedSet::SortedSet(const IntList & cpy) : IntList(cpy) {
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet() {
    
}

bool SortedSet::in(int value) const {
    for(IntNode *i = head; i; i = i -> next) {
        if(value == i -> value) {
            return true;
        }
    }
    return false;
}

void SortedSet::add(int value) {
    /*
    if(empty() || value > tail -> value) {
        push_back(value);
    }
    else if(value < head -> value) {
        push_front(value);
    }
    else {
        for(IntNode *prev = head; prev -> next; prev = prev -> next) {
            if(prev -> next -> value > value) {
                IntNode *node = new IntNode(value);
                node -> next = prev -> next;
                prev -> next = node;
                return;
            }
        }
    }
    */
   if(head == 0)
    {
        IntList::push_front(value);
    }
    else if(value > tail->value)
    {
        IntList::push_back(value);
    }
    else if(value < head->value)
    {
        IntList::push_front(value);
    }
    else if(head == tail && head->value != value)
    {
        if(value < head->value)
        {
            IntList::push_front(value);
        }
        else
        {
            IntList::push_back(value);
        }
    }
    else if(tail->value == value)
    {
        return;
    }
    else if(head->value == value)
    {
        return;
    }
    else
    {
        IntNode* temp = head;
        IntNode* firstList;
        while((temp != 0))
        {
            
            if(temp->next->value == value)
            {
                break;
            }
            else if(value < temp->next->value)
            {
                firstList = temp->next;
                temp->next = new IntNode(value);
                temp->next->next = firstList;
                break;
            }
            else
            {
                temp = temp->next;
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
