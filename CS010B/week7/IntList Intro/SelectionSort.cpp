#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void SelectionSort(vector<int>& v);

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

    SelectionSort(elements);

    cout << "\nSorted vector elements: \n";
    for (int i = 0; i < vSize; ++i) {
        cout << elements[i] << " ";
    }
    cout << endl << endl;

    return 0;
}

void SelectionSort(vector<int>& v) {
    //declare two indices and one minimum index saver
    int i, j, minimumIndex;  

    //for each index (except the last index of the vector)
    for (i = 0; i < v.size()-1; i++)  
    {  
        //set the minimum index as that index
        minimumIndex = i;  
        //starting from the saved index, search if there is a number smaller at than the saved index
        for (j = i+1; j < v.size(); j++)  
        //if there is a number smaller, save the index 
        if (v[j] < v[minimumIndex])  
            minimumIndex = j;  
        //finally, swap the original index and the smallest number index found with each other
        swap(v[minimumIndex], v[i]);  
    } 
}