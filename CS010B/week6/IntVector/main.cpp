#include <iostream>
#include <vector>
#include "IntVector.h"

using namespace std;

/* Size, Capacity, At Print Test */
void PrintVector(IntVector &t) {
    cout << endl << "size, cap " << t.size() << " " << t.capacity() << endl << "array: ";
    for (unsigned i = 0; i < t.size(); ++i) {
        cout << t.at(i) << " ";
    }
    cout << endl;
}

int main() {

    /* No Parameter Tests */
    IntVector v1;
    v1.push_back(5);    //push_back() test
    v1.push_back(5);
    v1.pop_back();      //pop_back() test
    PrintVector(v1); 

    /* One Parameter Tests */
    IntVector v2(10);
    v2.resize(20, 10);  //resize() two parameter test
    v2.insert(4, 12);   //insert() test
    v2.erase(9);        //erase() test
    v2.pop_back();
    v2.pop_back();
    PrintVector(v2);

    /* Two Parameter Tests */
    IntVector v3(5, 5);
    v3.empty();         //empty() test
    v3.resize(10, 10);
    v3.resize(5);       //resize() one parameter test
    PrintVector(v3);

    /* Assign Test */
    IntVector v4(20, 1);
    v4.assign(25, 5);
    PrintVector(v4);

    /* Reserve Test */
    IntVector v5;
    v5.reserve(3);
    v5.push_back(100);
    v5.push_back(200);
    v5.push_back(300);
    PrintVector(v5);

    /* Front and Back test */
    IntVector v6;
    v6.insert(0, 100);
    v6.insert(1, 200);
    PrintVector(v6);
    cout << "Front: " << v6.front() << endl << "Back: " << v6.back() << endl;
    
    return 0;
}