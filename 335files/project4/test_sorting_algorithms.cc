// Homework 4
// Testing Sorting Algorithms
// Ashfak Uddin

#include "Sort.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
using namespace std;


// Verifies that a vector is sorted given a comparator.
// I.e. it applies less_than() for consecutive pair of elements and returns true
// iff less_than() is true for all pairs.
template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than) {
  for (size_t i = 1; i < input.size(); i++)
  {
    if (input[i-1] != input[i] && !less_than(input[i-1], input[i]))
      return false;
  }
  return true;
}

// Computes duration given a start time and a stop time in nano seconds.
// Keep it in.
auto ComputeDuration(chrono::high_resolution_clock::time_point start_time, chrono::high_resolution_clock::time_point end_time) {
  return chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
}

template <typename Comparable, typename Comparator> 
void timingWrapper(vector<Comparable>& vec, Comparator less_than) 
{  
    vector<int> vec2{vec};       
    vector<int> vec3{vec};      
    vector<int> vec4{vec};      
    vector<int> vec5{vec};        
    cout << "Heapsort" << endl << endl;
    auto start = chrono::high_resolution_clock::now();   
    HeapSort(vec, less_than);   
    auto finish = chrono::high_resolution_clock::now();      
    cout << "Runtime: " << ComputeDuration(start, finish) << " ns" << endl;   
    cout << "Verified: " << VerifyOrder(vec, less_than) << endl << endl;     
    cout << "MergeSort" << endl << endl;
    start = chrono::high_resolution_clock::now();   
    MergeSort(vec2, less_than);   
    finish = chrono::high_resolution_clock::now();      
    cout << "Runtime: " << ComputeDuration(start, finish) << " ns" << endl;  
    cout << "Verified: " << VerifyOrder(vec2, less_than) << endl << endl;     
    cout << "QuickSort" << endl << endl;   
    start = chrono::high_resolution_clock::now();   
    QuickSort(vec3, less_than);   
    finish = chrono::high_resolution_clock::now();      
    cout << "Runtime: " << ComputeDuration(start, finish) << " ns" << endl;   
    cout << "Verified: " << VerifyOrder(vec3, less_than) << endl << endl;         
    cout << "Testing Quicksort Pivot Implementations" << endl;      
    cout << "Median of Three" << endl << endl;
    // not testing again because the QuickSort method called above   
    // uses the Median of Three implementation so I will just copy it over   
    cout << "Runtime: " << ComputeDuration(start, finish) << " ns" << endl;   
    cout << "Verified: " << VerifyOrder(vec3, less_than) << endl << endl;      
    cout << "Middle" << endl << endl;   
    start = chrono::high_resolution_clock::now();   
    QuickSort2(vec4, less_than);   finish = chrono::high_resolution_clock::now();      
    cout << "Runtime: " << ComputeDuration(start, finish) << " ns" << endl;   
    cout << "Verified: " << VerifyOrder(vec4, less_than) << endl << endl;       
    cout << "First" << endl << endl;   
    start = chrono::high_resolution_clock::now();   
    QuickSort3(vec5, less_than);   
    finish = chrono::high_resolution_clock::now();      
    cout << "Runtime: " << ComputeDuration(start, finish) << " ns" << endl;   
    cout << "Verified: " << VerifyOrder(vec5, less_than) << endl << endl; 
}

// Generates and returns random vector of size @size_of_vector.
vector<int> GenerateRandomVector(size_t size_of_vector) {
  // Use rand() to generate random integer
  // Add code
  srand(time(NULL)); 
  vector<int> res;
  for (size_t i = 0; i < size_of_vector; i++)
    res.push_back(rand() % 10);
  return res;
}

// Generates and returns sorted vector of size @size_of_vector.
// If @smaller_to_larger is true, returns vector sorted from small to large.
// Otherwise returns vector sorted from large to small
vector<int> GenerateSortedVector(size_t size_of_vector, bool smaller_to_larger) {
  vector<int> res;
  if (smaller_to_larger)
  {
    for (size_t i = 0; i < size_of_vector; i++)
    {
      res.push_back(i);
    } 
  }
  else
  {
    for (size_t i = size_of_vector; i > 0; i--)
    {
      res.push_back(i);
    } 
  }
  return res;
}


// Wrapper function to test different sorting algorithms. See homework's PDF for details.
void testSortingWrapper(int argc, char **argv) {
  const string input_type = string(argv[1]);
  const int input_size = stoi(string(argv[2]));
  const string comparison_type = string(argv[3]);
  if (input_type != "random" && input_type != "sorted_small_to_large" && input_type != "sorted_large_to_small") {
    cout << "Invalid input type" << endl;
    return;
  }
  if (input_size <= 0) {
    cout << "Invalid size" << endl;
    return;
  }
  if (comparison_type != "less" && comparison_type != "greater") {
    cout << "Invalid comparison type" << endl;
    return;
  }


  cout << "Running sorting algorithms: " << input_type << " " << input_size << " numbers " << comparison_type << endl;
  vector<int> input_vector;
  if (input_type == "random") {
    // Generate random vector @input_vector.
    input_vector = GenerateRandomVector(input_size);
    
  } else {
    // Generate sorted vector @input_vector.
    input_vector = GenerateSortedVector(input_size, comparison_type == "less");        
  }
  if (comparison_type == "less")    
      timingWrapper(input_vector, less<int>{});   
  else     
      timingWrapper(input_vector, greater<int>{});   

  // Call HeapSort / MergeSort / QuickSort  using appropriate input.
  // ...
  // if comparison type is "less" then call 
  // MergeSort(input_vector, less<int>{})
  // otherwise call
  // MergeSort(input_vector, greater<int>{})
  // ...
  // ^^SAME for HeapSort & QuickSort
  
  // Call quicksort with median of three as pivot / middle as pivot / first as pivot using appropriate input.
  // ...
  // if comparison type is "less" then call 
  // QuickSort(input_vector, less<int>{})
  // otherwise call
  // QuickSort(input_vector, greater<int>{})
  // ...
  // ^^SAME for QuickSort2 & QuickSort3

}

int main(int argc, char **argv) {
  // DO NOT CHANGE or ADD ANY CODE in this function.
 /* if (argc != 4) {
    cout << "Usage: " << argv[0] << "<input_type> <input_size> <comparison_type>" << endl;
    return 0;
  }
 /* vector<int> res = GenerateRandomVector(11);
  QuickSort3(res, greater<int>{});
  cout << VerifyOrder(res, greater<int>{}) << endl;
  for (int i: res)
    cout << i << " ";
  cout << endl;
  testSortingWrapper(argc, argv);
  */

  int num;
  cin >> num;
  for (int i = 0; i < num; i++)
  {
    for (int j = 0; j < num; j++)
    {
      if (j < num - i - 1)
      {
        cout << " ";
      }
      else
      {
        cout << "*";
      }
    }
    cout << endl;
  }
  return 0;
}
