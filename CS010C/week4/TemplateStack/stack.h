#include <iostream>
#include <stdexcept>

using namespace std;

#ifndef __STACK_H__
#define __STACK_H__

const int MAX_SIZE = 20;

template <typename T>
class stack {
    private:
        T data[MAX_SIZE];
        int size;
    public:
        stack();
        void push(T);
        void pop();
        T top() const;
        bool empty() const;
};

#endif

/* Constructor */
template <typename T>
stack<T>::stack() {
    size = 0;
}

/* Mutators */
template <typename T>
void stack<T>::push(T val) {
    if (size >= MAX_SIZE) {
        throw overflow_error("Called push on full stack.");
    }
    data[size] = val;
    size++;
}

template <typename T>
void stack<T>::pop() {
    if (empty()) {
        throw out_of_range("Called pop on empty stack.");
    }
    size--;
}

/* Accessors */
template <typename T>
T stack<T>::top() const {
    if (empty()) {
        throw underflow_error("Called top on empty stack.");
    }
    return data[size-1];
}

template <typename T>
bool stack<T>::empty() const {
    if (size == 0) {
        return true;
    }
    return false;
}

