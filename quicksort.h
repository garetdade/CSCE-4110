#ifndef QUICKSORT_H
#define QUICKSORT_H

// source for a lot of the code: https://www.techiedelight.com/hybrid-quicksort/

#include <vector>
#include <stdlib.h>
using namespace std;



// for swaping elements in a vector (vector, position 1, position 2)
void swap(vector<int> &a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

// finding the median of three for best possible pivot
int partition(vector<int> &a, int low, int high) {
    // Pick the rightmost element as a pivot from the array
    int pivot = a[high];

    // elements less than the pivot will be pushed to the left of `pIndex`
    // elements more than the pivot will be pushed to the right of `pIndex`
    // equal elements can go either way
    int pIndex = low;

    // each time we find an element less than or equal to the pivot, `pIndex`
    // is incremented, and that element would be placed before the pivot.
    for (int i = low; i < high; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a, i, pIndex);
            pIndex++;
        }
    }
    // swap `pIndex` with pivot
    swap(a, pIndex, high);

    // return `pIndex` (index of the pivot element)
    return pIndex;
}


void QuickSort(vector<int> &A, int low, int high, int par)
{
    while (low < high)
    {
        // switch to insertion sort if the size is smaller than partition limit given
        if (high - low < par)
        {
            insertionSort(A, low, high);
            break;
        }
        else {
            int pivot = partition(A, low, high);

            // tail call optimizations – recur on the smaller subarray
            if (pivot - low < high - pivot)
            {
                QuickSort(A, low, pivot - 1, par);
                low = pivot + 1;
            }
            else {
                QuickSort(A, pivot + 1, high, par);
                high = pivot - 1;
            }
        }
    }
}

#endif
