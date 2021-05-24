#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void Quicksort_midpoint(int numbers[], int i, int k);
void Quicksort_medianOfThree(int numbers[], int i, int k);
int Midpoint_partition(int numbers[], int i, int k);
int MedianOfThree_partition(int numbers[], int i, int k);
int MedianOfThree(int i, int j, int k);
void InsertionSort(int numbers[], int numbersSize);

const int NUMBERS_SIZE = 50000;
const int CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000;

int genRandInt(int low, int high) {
    return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[], int arr3[]) {
    for (int i = 0; i < NUMBERS_SIZE; ++i) {
        arr1[i] = genRandInt(0, NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

int main() {
    srand(time(nullptr));
    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];
    fillArrays(arr1, arr2, arr3);

    cout << "Midpoint Quicksort speed: ";
    clock_t Start = clock();
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE - 1);
    clock_t End = clock();
    int elapsedTime = (End - Start) / CLOCKS_PER_MS;
    cout << elapsedTime << "ms" << endl;

    cout << "Median-Of-Three Quicksort speed: ";
    Start = clock();
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE - 1);
    End = clock();
    elapsedTime = (End - Start) / CLOCKS_PER_MS;
    cout << elapsedTime << "ms" << endl;

    cout << "Insertion Sort speed: ";
    Start = clock();
    InsertionSort(arr3, NUMBERS_SIZE - 1);
    End = clock();
    elapsedTime = (End - Start) / CLOCKS_PER_MS;
    cout << elapsedTime << "ms" << endl;

    
    return 0;
}


void Quicksort_midpoint(int numbers[], int i, int k) {
    if (i < k) {
        int index = Midpoint_partition(numbers, i, k);
        Quicksort_midpoint(numbers, i, index);
        Quicksort_midpoint(numbers, index + 1, k);
    }
}

int Midpoint_partition(int numbers[], int i, int k) {
    bool partitioned = false;
    int midpoint = i + (k - i) / 2;
    int pivot = numbers[midpoint];
    while(!partitioned) {
        while (numbers[i] < pivot) {
            ++i;
        }
        while (numbers[k] > pivot) {
            --k;
        }
        if (i < k) {
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;
            ++i;
            --k;
        } else {
            partitioned = true;
        }
    }
    return k;
}


void Quicksort_medianOfThree(int numbers[], int i, int k) {
    if (i < k) {
        int index = MedianOfThree_partition(numbers, i, k);
        Quicksort_medianOfThree(numbers, i, index);
        Quicksort_medianOfThree(numbers, index + 1, k);
    }
}

int MedianOfThree_partition(int numbers[], int i, int k) {
    bool partitioned = false;
    int midpoint = MedianOfThree(i, i + (k - i) / 2, k);
    int pivot = numbers[midpoint];
    while(!partitioned) {
        while (numbers[i] < pivot) {
            ++i;
        }
        while (numbers[k] > pivot) {
            --k;
        }
        if (i < k) {
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;
            ++i;
            --k;
        } else {
            partitioned = true;
        }
    }
    return k;
}

int MedianOfThree(int i, int j, int k) {
    if (i > j) {
        if (j > k) {
            return j;
        } else if (i > k) {
            return k;
        } else {
            return i;
        }
    } else {
        if (i > k) {
            return i;
        } else if (j > k) {
            return k;
        } else {
            return j;
        }
    }
}

void InsertionSort(int numbers[], int numbersSize) {
    for (int i = 1; i < numbersSize; i++) {
        int j = i;
        while (j > 0 && numbers[j - 1] > numbers[j]) {
            int temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            j--;
        }
    }
}