#include <iostream>
using namespace std;

int main() {
    int* intpointer = nullptr;
    int minValue = 1;
    *intpointer = minValue;
    cout << intpointer;
    return 0;
}