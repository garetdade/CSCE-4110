/* Citation:
https://www.geeksforgeeks.org/merge-sort/
https://slaystudy.com/c-merge-sort-vector/
*/

#include <iostream>

using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(vector<int>& v, int s, int m, int e) {

    // temp is used to temporary store the vector obtained by merging
    // elements from [s to m] and [m+1 to e] in v
	vector<int> temp;

	int i, j;
	i = s;
	j = m + 1;

	// Looping through until one side is merged
	while (i <= m && j <= e) {
		// If left is smaller, place in temp vector. Else place right in temp vector
		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}
	}

	// Place remaning left elements in temp vector
	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	// Place remaning right elements in temp vector
	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	// Copy over the sorted temp back into the original vector 
	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(vector<int>& array, int const begin, int const end, int const k)
{
    if (end - begin <= k){
        insertionSort(array, begin, end); // Returns recursively
		}
    else if(begin < end){
        auto mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid, k);
        mergeSort(array, mid + 1, end, k);
        merge(array, begin, mid, end);
      }
}
