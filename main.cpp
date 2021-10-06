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
  string inFileName = "set1_1M.txt";
  string outFileName = "Output.txt";
  ifstream inputFile;
  ofstream outFile;

  // Opening file
  inputFile.open(inFileName.c_str());
  freopen(outFileName.c_str(),"w",stdout);

  // Test for opening fail
  if(!inputFile)
  {
     cout << "The file " << inFileName << " could not be opened." << endl;
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
  cout << "Finished!" << endl << "Duration: " << duration.count() << "microseconds."<< endl << endl;

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
  cout << "Finished!" << endl << "Duration: " << duration.count() << "microseconds."<< endl << endl;

  return 0;
}
