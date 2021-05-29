#ifndef __MAXHEAP_H__
#define __MAXHEAP_H__

#include "Key.h"

using namespace std;

const int MAX_CAPACITY = 10000;

class MaxHeap {
    private:
        Key* arr[MAX_CAPACITY];
        int s;
    public:
        MaxHeap() : s(0) {}
        void enqueue(const string &);
        Key* dequeue();
        bool empty() const;
        int size() const;
    private:
        void percolateUp(int);
        void percolateDown(int);
        int parent(int);
        int left(int);
        int right(int);

};

#endif