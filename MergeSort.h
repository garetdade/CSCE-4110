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

	while (i <= m && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

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
