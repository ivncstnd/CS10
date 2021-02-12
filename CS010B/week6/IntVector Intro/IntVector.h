#ifndef INTVECTOR_H
#define INTVECTOR_H

using namespace std;

class IntVector {
    private:
        unsigned _size;     //size
        unsigned _capacity; //cap
        int *_data;         //dynamic arr
    public:
        IntVector (unsigned capacity = 0, int value = 0); //Overloaded Constructor
        ~IntVector ();
        unsigned size () const;
        unsigned capacity () const;
        bool empty () const;
        const int & at (unsigned) const;
        int & at (unsigned);
        void insert (unsigned, int);
        void erase (unsigned);
        const int & front () const;
        int & front ();
        const int & back () const;
        int & back ();
        void assign (unsigned, int);
        void push_back (int);
        void pop_back ();
        void clear ();
        void resize (unsigned, int value = 0);
        void reserve (unsigned);
    private:
        void expand ();
        void expand (unsigned);
};

#endif