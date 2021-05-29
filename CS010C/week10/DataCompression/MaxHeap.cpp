#include "MaxHeap.h"

using namespace std;

void MaxHeap::enqueue(const string &token) {
    if (token == "") 
        return;
    if (s < MAX_CAPACITY) {
        for (int i = 0; i < s; i++) {
            if (arr[i]->token == token) {
                arr[i]->frequency += 1;
                percolateUp(i);
                return;
            }
        }
        Key* key = new Key(token);
        arr[s] = key;
        percolateUp(s);
        s++;
    }
}

Key* MaxHeap::dequeue() {
    Key* top = arr[0];
    if (s == 1) {
        arr[0] = 0;
        s = 0;
    }
    if(s > 1) {
        arr[0] = arr[s - 1];
        arr[s - 1] = 0;
        s--;
        percolateDown(0);
    }
    return top;
}

bool MaxHeap::empty() const {
    if (s == 0)
        return true;
    return false;
}

int MaxHeap::size() const {
    return s;
}

void MaxHeap::percolateUp(int index) {
    if(index > 0 && arr[index]->frequency > arr[parent(index)]->frequency) {
        Key* temp = arr[parent(index)];
        arr[parent(index)] = arr[index];
        arr[index] = temp;
        percolateUp(parent(index)); 
    }
}

void MaxHeap::percolateDown(int index) {
    int LI = left(index);
    int RI = right(index);
    int currMax = index;
    if (LI < s 
        && arr[LI]->frequency > arr[currMax]->frequency) {
        currMax = LI;
    }
    if (RI < s
        && arr[RI]->frequency > arr[currMax]->frequency) {
        currMax = RI;
    }
    if (currMax != index) {
        Key* temp = arr[index];
        arr[index] = arr[currMax];
        arr[currMax] = temp;
        percolateDown(currMax);
    }
}

int MaxHeap::parent(int index) {
    return (index - 1) / 2;
}

int MaxHeap::left(int index) {
    return (2 * index) + 1;
}

int MaxHeap::right(int index) {
    return (2 * index) + 2;
}