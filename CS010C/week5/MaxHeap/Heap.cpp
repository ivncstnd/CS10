#include "Heap.h"
#include <iostream>

using namespace std;

/* Constructor */
Heap::Heap() : numItems(0) 
{}

/* Mutators */
/* While the current size is not greater than the max size
append the new job to the end of the array and percolate up
until in correct position. Then increase the size to account 
for new Job. */
void Heap::enqueue(PrintJob *newJob) {
    if (numItems < MAX_HEAP_SIZE) {
        arr[numItems] = newJob;
        percolateUp(numItems);
        numItems++;
    }
}

/* If the job only has one job left, set the first index to 0 and make the size 0.
Otherwise, set the first index as the last job, set the last job as 0, and remove
the job by decrementing the size. Last, percolate the first index down to the correct
postion. */ 
void Heap::dequeue() {
    if (numItems == 1) {
        arr[0] = 0;
        numItems = 0;
        return;
    }
    if(numItems > 1) {
        arr[0] = arr[numItems - 1];
        arr[numItems - 1] = 0;
        numItems--;
        trickleDown(0);
    }
}

/* Print the highest priority job */
void Heap::print() {
    if(numItems == 0) {
        return;
    }
    cout << "Priority: " << highest()->getPriority() 
         << ", Job Number: " << highest()->getJobNumber()
         << ", Number of Pages: " << highest()->getPages() << endl;
}

/* Recursively check the left and right child to see if larger.
If either side is larger than its current parent node, swap
and recurse through the heap. */
void Heap::trickleDown(int index) {
    int left = leftIndex(index);
    int right = rightIndex(index);
    int currMax = index;
    if (left < numItems 
        && arr[left]->getPriority() > arr[currMax]->getPriority()) {
        currMax = left;
    }
    if (right < numItems
        && arr[right]->getPriority() > arr[currMax]->getPriority()) {
        currMax = right;
    }
    if (currMax != index) {
        PrintJob* temp = arr[index];
        arr[index] = arr[currMax];
        arr[currMax] = temp;
        trickleDown(currMax);
    }
}

/* If the current index is greater than its parent index, 
swap the 2 indexs and recurse until no longer true. */
void Heap::percolateUp(int index) {
    if(index && arr[index]->getPriority() > arr[parentIndex(index)]->getPriority()) {
        PrintJob *temp = arr[parentIndex(index)];
        arr[parentIndex(index)] = arr[index];
        arr[index] = temp;
        percolateUp(parentIndex(index)); 
    }
}


/* Accessors */
PrintJob* Heap::highest() {
    if (numItems == 0) {
        return nullptr;
    }
    return arr[0];
}

int Heap::parentIndex(int index) {
    return (index - 1) / 2;
}

int Heap::leftIndex(int index) {
    return (2 * index) + 1;
}

int Heap::rightIndex(int index) {
    return (2 * index) + 2;
}