#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    // Base Case
    if (arrSize == 1) {
        return &arr[0];
    }
    /**
    * This func recurses through min funcs until it hits base case.
    * Once the base case is hit, each case waits to compares its return 
    * to its current value. If the current value is smaller than the 
    * dereferenced current minumium, return the pointer of the current 
    * value in the array. Otherwise, return the current pointer.
    */
    const int *currMinPtr = min(arr, arrSize - 1);
    if (arr[arrSize - 1] < *currMinPtr) {
        return &arr[arrSize - 1];
    }
    return currMinPtr;
}