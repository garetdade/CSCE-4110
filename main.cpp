#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <ratio>
#include "InsertionSort.h"
#include "TimSort.h"
#include "MergeSort.h"
#include "RadixSort.h"
//#include "quicksort.h"

using namespace std;
using namespace std::chrono;

int main(){
  // Declarying variables
  int k, i, counter = 0;
  int size[20];
  vector<int> data[20];
  vector<int> vect;
  int element;
  string fileNames[20] = {"set1_1M.txt", "set1_10.txt", "set2_1M.txt", "set2_10.txt", "set3_1M.txt", "set3_10.txt", "set4_1M.txt", "set4_10.txt", "set5_1M.txt", "set5_10.txt", "set6_1M.txt", "set6_10.txt", "set7_1M.txt", "set7_10.txt", "set8_1M.txt", "set8_10.txt", "set9_1M.txt", "set9_10.txt", "set10_1M.txt", "set10_10.txt"};
  string inFileName = "set1_1M.txt";
  string outFileName = "Output.txt";
  ifstream inputFile[20];
  ofstream outFile;
  auto start = high_resolution_clock::now();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  double aver = 0.0;

  // Opening files
  for (i = 0; i < 20; i++){
    inputFile[i].open(fileNames[i].c_str());

    // Test for opening file
    if(!inputFile[i])
    {
       cout << "The file " << inFileName[i] << " could not be opened." << endl;
       return -1; // If a file did not open, stop program
    }

    // Placing data from file to Vector
    while (inputFile[i] >> element){
      data[i].push_back(element);
    }
    size[i] = data[i].size();

    // Closing File
    inputFile[i].close();
  }


  // Opening output File
  freopen(outFileName.c_str(),"w",stdout);


//---------------------------------Merge Sort (k = 10)---------------------------
  // Recording time stamp before sorting
  cout << "Running MergeSort(k = 10)" << endl;

  // Calling the sort algorithm
  k = 10;

  for (i = 0; i < 20; i++){
    vect = data[i];
    // Recording starting time of algorithm
    start = high_resolution_clock::now();

    // Calling the sorting algorithm
    mergeSort(vect, 0, 100000, k);

    // recording time stamp after sorting
    stop = high_resolution_clock::now();

    // Calculating the duration of the sorting algorithm
    duration = duration_cast<microseconds>(stop - start);
    aver += duration.count();
    counter++;
  }

  // Priting Results to output file
  cout << "Finished " << counter << " tests with a total runtime of " << aver << " microseconds!" << endl << "Average Duration: " << aver/20 << " microseconds."<< endl << endl;

  // Resetting average counter
  aver = 0;
  counter = 0;
//-------------------------------------------------------------------------------


//---------------------------------Merge Sort (k = 1000)---------------------------
  // Recording time stamp before sorting
  cout << "Running MergeSort(k = 1000)" << endl;

  // Calling the sort algorithm
  k = 1000;

  for (i = 0; i < 20; i++){
    vect = data[i];
    // Recording starting time of algorithm
    start = high_resolution_clock::now();

    // Calling the sorting algorithm
    mergeSort(vect, 0, 100000, k);

    // recording time stamp after sorting
    stop = high_resolution_clock::now();

    // Calculating the duration of the sorting algorithm
    duration = duration_cast<microseconds>(stop - start);
    aver += duration.count();
    counter++;
  }

  // Priting Results to output file
  cout << "Finished " << counter << " tests with a total runtime of " << aver << " microseconds!" << endl << "Average Duration: " << aver/20 << " microseconds."<< endl << endl;

  // Resetting average counter
  aver = 0;
  counter = 0;
//-------------------------------------------------------------------------------

/*
//---------------------------------Quick Sort (k = 10)---------------------------
  // Recording time stamp before sorting
  cout << "Running QuickSort" << endl;

  // Calling the sort algorithm
  k = 10;
  for (i = 0; i < 20; i++){
    vect = data[i];
    // Recording starting time of algorithm
    start = high_resolution_clock::now();

    // Calling the sorting algorithm
    QuickSort(vect, 0, size[i] - 1, k);

    // recording time stamp after sorting
    stop = high_resolution_clock::now();

    // Calculating the duration of the sorting algorithm
    duration = duration_cast<microseconds>(stop - start);
    aver += duration.count();
    counter++;
  }

  // Priting Results to output file
  cout << "Finished " << counter << "tests with a total runtime of " << aver << " microseconds!" << endl << "Average Duration: " << aver/20 << " microseconds."<< endl << endl;

  // Resetting average counter
  aver = 0;
  counter = 0;
//-------------------------------------------------------------------------------

//---------------------------------Quick Sort (k = 1000)---------------------------
  // Recording time stamp before sorting
  cout << "Running QuickSort" << endl;

  // Calling the sort algorithm
  k = 1000;
  for (i = 0; i < 20; i++){
    vect = data[i];
    // Recording starting time of algorithm
    start = high_resolution_clock::now();

    // Calling the sorting algorithm
    QuickSort(vect, 0, size[i] - 1, k);

    // recording time stamp after sorting
    stop = high_resolution_clock::now();

    // Calculating the duration of the sorting algorithm
    duration = duration_cast<microseconds>(stop - start);
    aver += duration.count();
    counter++;
  }

  // Priting Results to output file
  cout << "Finished " << counter << "tests with a total runtime of " << aver << " microseconds!" << endl << "Average Duration: " << aver/20 << " microseconds."<< endl << endl;

  // Resetting average counter
  aver = 0;
  counter = 0;
//-------------------------------------------------------------------------------

*/
//---------------------------------Radix Sort---------------------------
  // Recording time stamp before sorting
  cout << "Running RadixSort" << endl;

  // Calling the sort algorithm
  for (i = 0; i < 20; i++){
    vect = data[i];
    // Recording starting time of algorithm
    start = high_resolution_clock::now();

    // Calling the sorting algorithm
    radixSort(vect);

    // recording time stamp after sorting
    stop = high_resolution_clock::now();

    // Calculating the duration of the sorting algorithm
    duration = duration_cast<microseconds>(stop - start);
    aver += duration.count();
    counter++;
  }

  // Priting Results to output file
  cout << "Finished " << counter << " tests with a total runtime of " << aver << " microseconds!" << endl << "Average Duration: " << aver/20 << " microseconds."<< endl << endl;

  // Resetting average counter
  aver = 0;
  counter = 0;
//-------------------------------------------------------------------------------


//---------------------------------Tim Sort---------------------------
  // Recording time stamp before sorting
  cout << "Running TimSort" << endl;

  // Calling the sort algorithm
  for (i = 0; i < 20; i++){
    vect = data[i];
    // Recording starting time of algorithm
    start = high_resolution_clock::now();

    // Calling the sorting algorithm
    timSort(vect);

    // recording time stamp after sorting
    stop = high_resolution_clock::now();

    // Calculating the duration of the sorting algorithm
    duration = duration_cast<microseconds>(stop - start);
    aver += duration.count();
    counter++;
  }

  // Priting Results to output file
  cout << "Finished " << counter << " tests with a total runtime of " << aver << " microseconds!" << endl << "Average Duration: " << aver/20 << " microseconds."<< endl << endl;

  // Resetting average counter
  aver = 0;
  counter = 0;
//-------------------------------------------------------------------------------

  return 0;
}
