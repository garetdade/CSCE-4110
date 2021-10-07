#include<bits/stdc++.h>
using namespace std;
int arr[1000005];
int L[1000005], R[1000005];

void insertionSortT(vector<int>&arr,int L, int R)
{
	for (int i = L + 1; i <= R; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= L && arr[j] > temp)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

void mergeT(vector<int>&arr,int l, int m, int r)
{
	int len1 = m - l + 1, len2 = r - m;
	for (int i = 0; i < len1; i++)
		L[i] = arr[l + i];
	for (int i = 0; i < len2; i++)
		R[i] = arr[m + 1 + i];

	int i = 0;
	int j = 0;
	int k = l;

	while (i < len1 && j < len2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < len1)
	{
		arr[k] = L[i];
		k++;
		i++;
	}

	while (j < len2)
	{
		arr[k] = R[j];
		k++;
		j++;
	}
}

void timSort(vector<int>&arr)
{
	const int RUN = 32;
	const int n=1000000;
	for (int i = 0; i < n; i+=RUN)
		insertionSortT(arr,i, min((i+RUN-1),(n-1)));

	for (int size = RUN; size < n; size = 2*size)
	{
		for (int L = 0; L < n; L += 2*size)
		{
			int mid = L + size - 1;
			int R = min((L + 2*size - 1),(n-1));
			if(mid < R)
				mergeT(arr,L, mid, R);
		}
	}
}
