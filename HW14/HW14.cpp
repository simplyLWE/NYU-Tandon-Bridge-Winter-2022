/*

Assignment:
-----------

(Weiss 7.40):
The following divide-and-conquer algorithm is proposed for finding the simultaneous maximum and minimum:

If there is one item, it is the maximum and minimum,
and if there are two items, then compare them,
and in one comparison you can find the maximum and minimum.
Otherwise, split the input into two halves, divided as evenly as possibly
(if N is odd, one of the two halves will have one more element than the other).
Recursively find the maximum and minimum of each half,
and then in two additional comparisons produce the maximum and minimum for the entire problem.

*/

#include <iostream>
#include <vector>
using namespace std;

void getMaxMin(vector<int> A, int low, int high);

/*
TO-DO
[ ] Fix logic of recursive max & min
*/

int main()
{
  // vector<int> arr = {5, 2, 1, 3, 6, 4};
  vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
  // vector<int> arr = {7, 2, 9, 3, 1, 6, 7, 8, 4};
  // vector<int> arr = {1, 2, 3, 4, 5, 6};
  int size = arr.size();
  getMaxMin(arr, 0, size - 1);
}

void getMaxMin(vector<int> A, int low, int high)
{
  int max = 0;
  int min = 0;
  
  // 1 Element Array
  if (low == high)
  {
    max = A[low];
    min = A[low];
    cout << "Max: " << max 
      << " | Min: " << min << endl;
    return;
  }
  // 2 Element Array 
  else if (low + 1 == high)
  {
    if (A[low] < A[high])
    {
      max = A[high];
      min = A[low];
      cout << "Max: " << max 
      << " | Min: " << min << endl;
    }
    else if (A[low] >= A[high])
    {
      max = A[low];
      min = A[high];
      cout << "Max: " << max 
      << " | Min: " << min << endl;
    }
  }
  // 3+ Element Array
  else
  {
    int mid = (low + high) / 2;
    if (low < high)
    {
      getMaxMin(A, low, mid);        // Recursively get max & min of 1st half
      getMaxMin(A, mid + 1, high);   // Recursively get max & min of 2nd half
    }
  }
}