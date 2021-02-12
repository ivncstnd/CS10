#include <iostream>
#include <array>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

/* Constructor */
// Variables are adjusted via overloaded constructor initalized in header file
// Assign variables to respective private member 
// Initalize array values given appropriate capacity (e.g. not null)
IntVector::IntVector(unsigned capacity, int value) {
    _capacity = capacity;
    _size = capacity;
    _data = new int [capacity];
    if(capacity != 0) {
        for (unsigned i = 0; i < capacity; ++i) {
            _data[i] = value;
        }
    }
}

/* Deconstructor */
// Frees dynamic array from the heap
IntVector::~IntVector() {
    delete [] _data;
}

/* Accessors */
// Access private member size
unsigned IntVector::size() const {
    return _size;
}

// Access private member capacity
unsigned IntVector::capacity() const {
    return _capacity;
}

// Checks to see if the vector is empty
bool IntVector::empty() const {
    if (_size == 0) {
        return true;
    }
    else {
        return false;
    }
}

// Returns an immutable value from array from index
// Checks to see if index is out of bounds
// If true, throw out of range exception
const int & IntVector::at(unsigned index) const {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

// Returns an immutable first value from array
const int & IntVector::front() const {
    return _data[0];
}

// Returns an immutable last value from array
const int & IntVector::back() const {
    return _data[_size-1];
}

/* Mutators */
// Inserts a value into the array on any appropriate index 
// Adjusts size and capacity as needed
// To insert, value is inserted at the end of array and swaps to its correct index
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

// Removes a value from the array from any appropriate index
// To erase, value is swapped to the ned of the array and the size decremented, losing access to the value
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

// Appends to a value to the end of an array
// Modifies capacity as needed
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

// Removes a value from the end of an array 
// Does not check for out of range
void IntVector::pop_back() {
    --_size;
}

// Removes all values from a vector
void IntVector::clear() {
    _size = 0;
}

// Resizes the vector to the according size value
// Checks whether the capacity is large via double or appending the new size
// Passes a optional value assignment once a resize has occured
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

// Reserves a specified capacity
void IntVector::reserve(unsigned n) {
    if(n >= _capacity) {
        expand(n - _capacity);
    } 
}

// Reserves a specified capcity and fills capacity with value parameter
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

// Returns a mutable value from array from index
int & IntVector::at(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

// Returns a mutable first value from array
int & IntVector::front() {
    return _data[0];
}

// Returns a mutable last value from array
int & IntVector::back() {
    return _data[_size-1];
}

/* Private Helpers */
// Expand raises the total capacity of the dynamic array when called
// Because vectors are flexible with size calls, expand allocates needed memory to hold such values
// The functions create a new dynamic array with a adjusted capacity cap
// Values stored in the old dynamic array are copied into the new one then letting the old array be freed
// The capacity change is offically declared and the temporary refit array is pointed to the private member dynamic array
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