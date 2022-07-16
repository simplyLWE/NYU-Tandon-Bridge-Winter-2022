/*

Assignment:
-----------

Give a recursive implement to the following functions:

a. int sumOfSquares(int arr[], int arrSize)
    This function is given arr, an array of integers, and its logical size, arrSize.
    When called, it returns the sum of the squares of each of the values in arr.

    For example, if arr is an array containing [2, -1, 3, 10],
    calling will return 114 (since, 22 + (-1)2 + 32 + 102 = 114).

b. bool isSorted(int arr[], int arrSize)
    This function is given arr, an array of integers, and its logical size, arrSize.
    When called, it should return true if the elements in arr are sorted in an ascending order,
    or false if they are not.

*/

#include <iostream>
#include <cmath>
using namespace std;

int squares_sum(int arr[], int size);
bool is_sorted(int arr[], int size);

int main() 
{
  //int arr[] = {1, 2, 3, 4}; // Test sorted
  //int arr[] = {1, 2, 3, 0}; // Test sorted
  int arr[] = {2, -1, 3, 10};
  int size = 4;

  cout << "SECTION A:" << endl;
  cout << squares_sum(arr, size) << endl; // Expect 114
  cout << endl;
  
  cout << "SECTION B:" << endl;
  if (!is_sorted(arr, size))
  {
    cout << "Array is NOT sorted in ascending order." << endl;
  }
  else if (is_sorted(arr, size))
  {
    cout << "Array is sorted is ascending order." << endl;
  }
  
  return 0;
}

bool is_sorted(int arr[], int size)
{
  // Base Case
  if (size == 1)
  {
    return true;  
  }
  // Recursive Case
  else
  {
    if (arr[size - 1] > arr[size - 2])  // Sorted
    {
      return is_sorted(arr, size - 1);
    }
    else if (arr[size - 1] < arr[size - 2])  // Not sorted
    {
      return false;
    }
  }
}

// Iterative Implementation
// bool is_sorted(int arr[], int size)
// {
//   for (int i = 0; i < size - 1; i++)
//   {
//     // Stay within array bounds
//     if (arr[i] != size - 1 && arr[i] > arr[i + 1]) 
//     {
//       return false;
//     }
//     else
//     {
//       return true;
//     }
//   }
// }

// Uses cmath function: pow(base, exponent)
int squares_sum(int arr[], int size)
{
  int sum = 0;
  // Base Case
  if (arr[size] == arr[0])
  {
    return 0;
  }
  // Recursive Case
  else
  {
    sum += pow(arr[size - 1], 2);
    return squares_sum(arr, size - 1) + sum;
  }
}
// Iterative Implementation
// int squares_sum(int arr[], int size)
// {
//   int square = 0, sum = 0;
//   for (int i = 0; i < size; i++)
//   {
//     square = arr[i] * arr[i];
//     sum += square;
//   }
//   return sum;
// }