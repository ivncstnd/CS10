#include <iostream>
#include <array>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

/* Constructor */
IntVector::IntVector() {
    _capacity = 0;
    _size = 0;
    _data = new int [0];
}

IntVector::IntVector(unsigned size) {
    _capacity = size;
    _size = size;
    _data = new int [size];
    for (unsigned i = 0; i < size; ++i) {
        _data[i] = 0;
    }
}

IntVector::IntVector(unsigned size, int value) {
    _capacity = size;
    _size = size;
    _data = new int [size];
    for (unsigned i = 0; i < size; ++i) {
        _data[i] = value;
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
    if(index >= _size) {
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