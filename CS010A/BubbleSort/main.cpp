/* Example:
 * vector <5, 3, 1, 2, 4> ; size = 5
 *   for i = 0, [0,4), going up 1 each cycle: 0, 1, 2, 3
 *      for j = 0, [0,4), going up 1 each cycle: 0, 1, 2, 3
 *            check if j > j+1 : | 0[5] > 1[3] 2[1] 3[2] 4[4]
 *            if true, swap values with memory location: 0[3] | 1[5] 2[1] 3[2] 4[4]
 *      repeat until second last value is compared (last value has nothing to compare, that's why size-1)
 */

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void Swap(int& x, int& y);
void BubbleSort(vector<int>& myVec);

int main() {

    unsigned int vSize = 20;
    srand(time(nullptr));                       // pseudo-random seed value based on system time.

    cout << "\nVector size: " << vSize;

    vector<int> elements(vSize);

    cout << "\nRandom vector elements: \n";
    for (int i = 0; i < vSize; ++i) {
        elements[i] = (rand() % 20) + 1;     // pseudo-random values between 1-20.
        cout << elements[i] << " ";
    }
    cout << endl;

    BubbleSort(elements);

    cout << "\nSorted vector elements: \n";
    for (int i = 0; i < vSize; ++i) {
        cout << elements[i] << " ";
    }
    cout << endl << endl;

    return 0;
}

void Swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void BubbleSort(vector<int>& myVec) {
    for (unsigned int i = 0; i < myVec.size() - 1; i++) {
        for (unsigned int j = 0; j < myVec.size() - 1; j++) {
            if (myVec[j] > myVec[j+1]) {
                Swap(myVec[j], myVec[j+1]);
            }
        }
    }
}