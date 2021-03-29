/**
 * The goal of this problem is to write the merge function that, given a destination array and 2 source arrays that are both sorted, recursively merges the 2 source arrays into the destination array such that destination array will also be sorted.
 * You may assume the 2 source arrays are sorted and that the capacity of the destination array is large enough to store the contents of the 2 source arrays.\
 * 
 * For example, running the merge function on the arrays
 * source1: 1 3 4 6
 * source2: 2 5 6 8 9
 * 
 * would result in the destination array containing
 * destination: 1 2 3 4 5 6 6 8 9
 * 
 * You must do this recursively. If you use any type of loop, or global or static variables you will lose a large number of points on this problem. 
 * Your solution should be O(n), where n is the combined sizes of the 2 source arrays. However, less efficient solutions can still receive partial credit.
 * You may not change the main function at all.
 * You may not use any standard library functions.
 */

#include <iostream>

using namespace std;

void displayArray(const int arr[], int arrSize) {
   if (arrSize > 0) {
      cout << arr[0];
      for (int i = 1; i < arrSize; ++i) {
         cout << ' ' << arr[i];
      }
   }
}

// helper func
void mergeh(int destination[], int source1[], int source2[], int source1Size, int source2Size, int index1, int index2, int destSize) {
   if(index1 < source1Size && index2 < source2Size) {
      if(source1[index1] < source2[index2]) {
         destination[destSize] = source1[index1];
         mergeh(destination, source1, source2, source1Size, source2Size, index1 + 1, index2, destSize + 1);
      }
      else {
         destination[destSize] = source2[index2];
         mergeh(destination, source1, source2, source1Size, source2Size, index1, index2 + 1, destSize + 1);
      }
   }
   else {
      if (index1 < source1Size) {
         destination[destSize] = source1[index1];
         mergeh(destination, source1, source2, source1Size, source2Size, index1 + 1, index2, destSize + 1);
      }
      else if (index2 < source2Size) {
         destination[destSize] = source2[index2];
         mergeh(destination, source1, source2, source1Size, source2Size, index1, index2 + 1, destSize + 1);
      }
   }
}

void merge(int destination[], int source1[] , int source2[], int source1Size, int source2Size) {
   if(source1Size != 0 || source2Size != 0) {
      mergeh(destination, source1, source2, source1Size, source2Size, 0, 0, 0);   
   }
}


int main() {
  int destination[50] = {0};

  int left0[] = { 1, 3, 5, 7 };
  int rght0[] = { 2, 4, 6, 8 };
  
  int left1[] = { 1, 3, 5, 7 };
  int rght1[] = { 8, 10, 12, 14 };

  int left2[] = { 9, 10, 12, 14 };
  int rght2[] = { 2, 4, 6, 8 };

  int left3[] = { -7, -3, 2, 5 };
  int rght3[] = { -1, 2, 6, 8, 9, 12 };

  int left4[] = { 1, 3, 5, 7, 8, 10, 15, 21 };
  int rght4[] = { 2, 4, 4, 5 };

  int left5[] = { 1 };
  int rght5[] = { 2 };
  
  int left6[] = { 2 };
  int rght6[] = { -2 };

  int left7[] = { };
  int rght7[] = { 2 };

  int left8[] = { 11 };
  int rght8[] = { };
  
  int left9[] = { };
  int rght9[] = { };

  cout << "Enter a test case #: ";
  int testCase;
  cin >> testCase;
  cout << endl;

  cout << "Test #" << testCase << " Output: ";
  if (testCase == 0) {
    merge(destination, left0, rght0, 4, 4);
    displayArray(destination, 20);
    cout << endl;
  } else if (testCase == 1) {
    merge(destination, left1, rght1, 4, 4);
    displayArray(destination, 20);
    cout << endl;
  } else if (testCase == 2) {
    merge(destination, left2, rght2, 4, 4);
    displayArray(destination, 20);
    cout << endl;
  } else if (testCase == 3) {
    merge(destination, left3, rght3, 4, 6);
    displayArray(destination, 20);
    cout << endl;
  } else if (testCase == 4) {
    merge(destination, left4, rght4, 8, 4);
    displayArray(destination, 20);
    cout << endl;
  } else if (testCase == 5) {
    merge(destination, left5, rght5, 1, 1);
    displayArray(destination, 20);
    cout << endl;
  } else if (testCase == 6) {
    merge(destination, left6, rght6, 1, 1);
    displayArray(destination, 20);
    cout << endl;
  } else if (testCase == 7) {
    merge(destination, left7, rght7, 0, 1);
    displayArray(destination, 20);
    cout << endl;
  } else if (testCase == 8) {
    merge(destination, left8, rght8, 1, 0);
    displayArray(destination, 20);
    cout << endl;
  } else if (testCase == 9) {
    merge(destination, left9, rght9, 0, 0);
    displayArray(destination, 20);
    cout << endl;
  }
}
