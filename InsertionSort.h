/* Citation:
https://www.geeksforgeeks.org/insertion-sort/
*/
#include <iostream>

using namespace std;

void insertionSort(vector<int>& arr, int begin, int end){
  // Declaring variables
  int i, key, j;

  // Looping through array
  for (i = begin; i <= end; i++){
    // Placing element i into key to be compared
    key = arr[i];
    // J is the previous element to be compared
    j = i - 1;

    // Move elements that are greater than the key to a position ahead of them
    while(j >= 0 && arr[j] > key){
      arr[j+1] = arr[j];
      j = j-1;
    }
    arr[j+1] = key;
  }
}
