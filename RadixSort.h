#include <bits/stdc++.h>
using namespace std;
void radixSort(vector<int>&arr) {
  const int n = 1000000;
  int M = 2;
   int i, j, m, p = 1, index, temp, count = 0;
   list<int> pocket[10];
   for(i = 0; i< M; i++) {
      m = pow(10, i+1);
      p = pow(10, i);
      for(j = 0; j<n; j++) {
         temp = arr[j]%m;
         index = temp/p;
         pocket[index].push_back(arr[j]);
      }
      count = 0;
      for(j = 0; j<10; j++) {
         while(!pocket[j].empty()) {
            arr[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }
   }
}
