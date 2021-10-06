#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include "InsertionSort.h"
#include "MergeSort.h"

using namespace std;
using namespace std::chrono;

int main(){
  // Declarying variables
  int k;
  int size;
  vector<int> data;
  int element;
  string fileName = "set1_1M.txt";
  ifstream inputFile;

  // Opening file
  inputFile.open(fileName.c_str());

  // Test for opening fail
  if(!inputFile)
  {
     cout << "The file " << fileName << " could not be opened." << endl;
  } // END if(!inputFile)


  while (inputFile >> element){
    data.push_back(element);
  }

  size = data.size();

  // Recording time stamp before sorting
  cout << "Running MergSort(k = 10)" << endl;
  auto start = high_resolution_clock::now();

  // Calling the sort algorithm
  k = 10;
  mergeSort(data, 0, size - 1, k);

  // recording time stamp after sorting
  auto stop = high_resolution_clock::now();

  // Calculating the duration of the sorting algorithm
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Duration of MergSort(k = 10): " << duration.count() << "microseconds."<< endl;

  // Recording time stamp before sorting
  cout << "Running MergSort(k = 100)" << endl;
  start = high_resolution_clock::now();

  // Calling the sort algorithm
  k = 100;
  mergeSort(data, 0, size - 1, k);

  // recording time stamp after sorting
  stop = high_resolution_clock::now();

  // Calculating the duration of the sorting algorithm
  duration = duration_cast<microseconds>(stop - start);
  cout << "Duration of MergSort(k = 10): " << duration.count() << "microseconds."<< endl;

  return 0;
}
