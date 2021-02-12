#ifndef INTVECTOR_H
#define INTVECTOR_H

using namespace std;

class IntVector {
    private:
        unsigned _size;     //size
        unsigned _capacity; //cap
        int *_data;         //dynamic arr
    public:
        IntVector();
        IntVector(unsigned);
        IntVector(unsigned, int);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned) const;
        const int & front() const;
        const int & back() const;
};

#endif