# CSCE-4110 hw2

Part 1: Comparing Sorting Algorithms. 
  1. Create 10 sets of 1 million integers. Use random numbers to generate the inputs such that the sets have sufficiently diverse set of numbers.
  
  2. Obtain implementations of the following algorithms. You can use implementations availableonline, and modify them accordingly, as long as you cite the source.
      
      •Mergesort(k) –reduce until partitions are of size k=10  and  then  use  insertion  sort
      •Mergesort(k) –reduce until partitions are of size k=1000  and  then  use  insertion  sort
      •Quicksort(k) –reduce until partitions are of size k=10  and  then  use  insertion  sort
      •Quicksort(k) –reduce until partitions are of size k=1000  and  then  use  insertion  sort
      •Radix Sort
      •Tim Sort (https://en.wikipedia.org/wiki/Timsort)
     
     There are 6 algorithms Mergesort(10), Mergesort(1000), Quicksort(10), Quicksort(1000), RadixSort, Timsort.
      
  3. For each algorithm sort each of the ten sets (60 sorts in total) and compute the averagetime for each run. Discuss which algorithms are faster and why.
  
  4. Repeat the same experiment with 10 sets of 1 million integers, except in this case the integer values can be from 1 to 10 only. 
 
  Submit all the associated codes, and results and provide enough data to show your results. 
  We may run some of the codes to check, so your codes should be executable on CSE machines.  
  
  
Part 2: Measuring Signal Strength (20)
  Consider that you are testing how far a cell phone tower can send its signal. 
  To do so, you have marked testing spots of increasing distance going away from the tower.  
  The first testingspot is at distance of 1 unit, the second is at distance of 2 unit, and so on.  
  A test is when youstand at a designated spot and try to see if you can receive the signal.
  The conditions for the test are as follows: 
    If the signal can be received at the spot at distance n, it can also be received at all spots at distance <n 
    If the signal cannot be received at thespot at distance n, it also cannot be received at all spots at distance >n
    If you cannot receivea signal then you have to call the headquarters to let them know using a special phone that uses a different wireless connection.  
    However, since you have low battery on the special phone, you can only make 2 calls at most.
  Given these conditions what is the minimum number of tests that you need to do, given that you have k test spots?
  The number of tests will be a function of k.  
  Explain your answer.
    [HINT: This a well-known computer science problem, and you may find a solution online.
    However, the online problem will not be the same “story” as given here.  
    If you can find ananalogous problem you can use the answer as long as you cite the source.]

  
  To run the code, compile main.cpp
  We put all the sorting algorithms as functions in the main.cpp
