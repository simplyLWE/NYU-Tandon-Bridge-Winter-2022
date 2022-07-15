/*

Assignment:
-----------

Implement the function:
int* findMissing(int arr[], int n, int& resArrSize)

This function gets an array of integers arr and its logical size n.
All elements in arr are in the range {0, 1, 2, ... , n}.

Note that since the array contains n numbers taken from a range of size n + 1,
there must be at least one number that is missing (could be more than one number missing, if there are duplicate values in arr).

When called, it should create and return a new array, that contains all the numbers in range {0, 1, 2, ... , n} that are not in arr.
The function should also update the output parameter, resArrSize, with the logical size of the new array that was created.

For example, if arr = [3, 1, 3, 0, 6, 4], after calling findMissing(arr, 6, resArrSize),
the function should create and return an array that contains [2, 5], and update the value in resArrSize to be 2.

Implementation requirements:
1. Your function should run in linear time. That is, it should run in 𝜃(n).
2. Write a main() program that tests this function.

*/

#include <iostream>
using namespace std;

void print_arr(int arr[], int size);
int* sort_arr(int arr[], int size);
int* find_missing(int arr[], int arr_size, int& new_arr_size);

// Flag used to indicated a value is missing from array
const int MISSING = -1;

int main()
{
  // ORIGINAL ARRAY
  int size = 6;
  int arr[] = {3,1,3,0,6,4};  // missing: 2,5
  // range[]= {0,1,2,3,4,5,6}
  
  // TEST ARRAYS
  // int size = 6;
  // int arr[] = {2,1,5,0,4,4};  // missing: 3,6
  // int size = 7;
  // int arr[] = {2,1,5,0,4,4,3};  // missing: 6,7
  // int size = 8;
  // int arr[] = {2,1,5,0,4,4,3,6};  // missing: 7,8
  // int size = 8;
  // int arr[] = {2,1,5,7,4,4,3,6};  // missing: 0,8

  cout << "\nOriginal Array: " << endl;
  print_arr(arr, size);

  // Create new array of missing values
  int new_arr_size = 0; // Will be updated in place
  int* new_arr = find_missing(arr, size, new_arr_size);
  
  cout << "\nMissing Values Array:" << endl;
  print_arr(new_arr, new_arr_size);

  // Free up memory allocation, since no longer needed
  delete [] new_arr;
  new_arr = NULL;

  return 0;
}

int* find_missing(int arr[], int arr_size, int& new_arr_size)
{
  int range = arr_size + 1; // Get range of original array

  // Sort array
  int* sorted = sort_arr(arr, arr_size);
  
  // Iterate over range of sorted array to count missing values
  // -1 indicates the value is missing
  int count_missing = 0;
  for (int i = 0; i < range; i++)
  {
    if (sorted[i] == MISSING)
    {
      count_missing++;
    }
  }

  // Set number of missing values to create size of new array
  int missing_arr_size = count_missing;
  int* missing_arr = new int[missing_arr_size];

  // Iterate over sorted array and copy values into missing values array
  int arr_index = 0;
  for (int i = 0; i < range; i++)
  {
    if (sorted[i] == MISSING)
    {
      sorted[i] = i;  // Set back to actual missing value instead of -1
      missing_arr[arr_index] = sorted[i];
      arr_index++;
    }
  }

  // Update size of array to be passed back into main
  new_arr_size = missing_arr_size;

  // Free up memory allocation, since no longer needed
  delete [] sorted;
  sorted = NULL;
 
  return missing_arr;
}

int* sort_arr(int arr[], int size)
{
  int range = size + 1; // Get range of original array

  int* sort = new int[range];

  // Init array with -1:
  // Prevents garbage values
  // Indicates value is missing from array
  for (int i = 0; i < range; i++)
  { 
    sort[i] = MISSING;
  }

  // Copy values from original array to become index of sorted array
  for (int i = 0; i < size; i++)
  {
    sort[arr[i]] = arr[i];
  }
  return sort;
}

void print_arr(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";  
  }
  cout << endl;
}