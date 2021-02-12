#include <iostream>
#include <array>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

/* Constructor */
IntVector::IntVector(unsigned capacity, int value) {
    _capacity = capacity;
    _size = capacity;
    if(capacity != 0) {
        _data = new int [capacity];
        for (unsigned i = 0; i < capacity; ++i) {
            _data[i] = value;
        }
    }
    else {
        _data = new int [0];
    }
}

/* Deconstructor */
IntVector::~IntVector() {
    delete [] _data;
}

/* Accessors */
unsigned IntVector::size() const {
    return _size;
}

unsigned IntVector::capacity() const {
    return _capacity;
}

bool IntVector::empty() const {
    if (_size == 0) {
        return true;
    }
    else {
        return false;
    }
}

const int & IntVector::at(unsigned index) const {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

const int & IntVector::front() const {
    return _data[0];
}

const int & IntVector::back() const {
    return _data[_size-1];
}

/* Mutators */
void IntVector::insert(unsigned index, int value) {
    if (index > _size) {
        throw out_of_range("IntVector::insert_range_check");
    }
    if (_size == 0) {
        expand(1);
    }
    else if (_size >= _capacity) {
        expand();
    }
    _data[_size] = value;
    ++_size;
    for (unsigned i = (_size - 1); i > index; --i) {
        int temp = _data[i];
        _data[i] = _data[i - 1];
        _data[i - 1] = temp;
    }
}

void IntVector::erase(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::erase_range_check");
    }
    for(unsigned i = index; i < _size - 1; ++i) {
        int temp = _data[i];
        _data[i] = _data[i + 1];
        _data[i + 1] = temp;
    }
    --_size;
}

void IntVector::push_back(int value) {
    if (_capacity == 0) {
        expand(1);
    }
    else if (_size >= _capacity) {
        expand();
    }
    _data[_size] = value;
    ++_size;
}

void IntVector::pop_back() {
    --_size;
}

void IntVector::clear() {
    _size = 0;
}

void IntVector::resize(unsigned size, int value) {
        if (_size == 0) {
        expand(size);
        _size = size;
    }
    else if (size <= _size) {
        _size = size;
    }
    else {
        if (size > _capacity) {
            if (size <= (_capacity * 2)) {
                expand();
            }
            else {
                expand(size - _capacity);
            }
        }
    }
    for(unsigned i = _size; i < size; ++i) {
        _data[i] = value;
    }
    _size = size;
}

void IntVector::reserve(unsigned n) {
    if(n >= _capacity) {
        expand(n - _capacity);
    } 
}

void IntVector::assign(unsigned n, int value) {
    _size = n;
    if (n > _capacity) {
            if (n <= (_capacity * 2)) {
                expand();
            }
            else {
                expand(n - _capacity);
            }
        }
    for (unsigned i = 0; i < _size; ++i) {
        _data[i] = value;
    }
}

int & IntVector::at(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

int & IntVector::front() {
    return _data[0];
}

int & IntVector::back() {
    return _data[_size-1];
}

/* Private Helpers */
void IntVector::expand() {
    int* refit = new int [_capacity * 2];
    for (unsigned i = 0; i < _size; ++i) {
        refit[i] = _data[i];
    }
    delete [] _data;
    _capacity *= 2;
    _data = refit;
}

void IntVector::expand(unsigned amount) {
    int* refit = new int [_capacity + amount];
    for (unsigned i = 0; i < _size; ++i) {
        refit[i] = _data[i];
    }
    delete [] _data;
    _capacity += amount;
    _data = refit;
}