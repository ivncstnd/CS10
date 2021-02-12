#include <iostream>
#include <array>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

int main() {
    cout << "No parameter vector" << endl;
    IntVector NoParam;
    cout << "No parameter size: " << NoParam.size() << endl;
    cout << "No parameter capacity: " << NoParam.capacity() << endl;
    cout << "No parameter is empty: " << NoParam.empty() << endl;
    
   
    cout << endl << "One parameter vector" << endl;
    IntVector OneParam(5);
    cout << "One parameter size: " << OneParam.size() << endl;
    cout << "One parameter capacity: " << OneParam.capacity() << endl;
    cout << "One parameter is empty: " << OneParam.empty() << endl;
    cout << "One parameter at: " << OneParam.at(2) << endl;

    cout << endl << "Two parameter vector" << endl;
    IntVector TwoParam(3, 9);
    cout << "Two parameter size: " << TwoParam.size() << endl;
    cout << "Two parameter capacity: " << TwoParam.capacity() << endl;
    cout << "Two parameter is empty: " << TwoParam.empty() << endl;
    cout << "Two parameter at: " << TwoParam.at(1) << endl;
    
    cout << "Front and back test" << endl;
    cout << "Front: " << OneParam.front() << endl;
    cout << "Back: " << TwoParam.back() << endl;

    cout << "Out of range: " << TwoParam.at(4) << endl;
    cout << "Out of range: " << NoParam.at(0) << endl;
    
    return 0;
}