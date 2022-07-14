/*

Assignment:
-----------

Implement the function:
void oddsKeepEvensFlip(int arr[], int arrSize)

This function gets an array of integers arr and its logical size arrSize.
When called, it should reorder the elements of arr so that:
1. All the odd numbers come before all the even numbers
2. The odd numbers will keep their original relative order
3. The even numbers will be placed in a reversed order (relative to their original order).

For example, if arr = [5, 2, 11, 7, 6, 4],
after calling oddsKeepEvensFlip(arr, 6), arr will be: [5, 11, 7, 4, 6, 2]

Implementation requirements:
1. Your function should run in linear time.
   That is, if there are n items in arr, calling oddsKeepEvensFlip(arr, n) will run in 𝜃(n).
2. Write a main() program that tests this function.

*/

#include <iostream>
using namespace std;

void print_array(int arr[], int arr_size);
void keep_odds(int arr[], int arr_size);
void flip_evens(int arr[], int arr_size);
void swap_value(int &a, int &b);

int main()
{
  // Test Arrays
  int arr[] = {5, 2, 11, 7, 6, 4};
  int arr_size = 6;
  // int arr[] = {22, 44, 66, 88, 99, 55, 77, 33};
  // int arr_size = 8;
  
  cout << "Original Array: " << endl;
  print_array(arr, arr_size);
  cout << endl;

  // Function Call
  cout << "New Array: " << endl;
  keep_odds(arr, arr_size);
  flip_evens(arr, arr_size);
  print_array(arr, arr_size);
    
  return 0;
}

void flip_evens(int arr[], int arr_size)
{
  int beg = 0;
  int end = arr_size - 1;

  // Compare beginning to end values approaching middle
  while (beg < end)
  {
    // If odd, leave as is and step in
    if (arr[beg] % 2 != 0)
    {
       beg++;
    }
    // If beginning and end is even, swap, and step in
    if (arr[beg] % 2 == 0 && arr[end] % 2 == 0)
    {
      swap_value(arr[beg],arr[end]);
      beg++;
      end--;
    }
  }
}

void swap_value(int &a, int &b)
{
   int t = a; // Preserve a
   a = b; // Put b into a
   b = t; // Put a into b
}

void keep_odds(int arr[], int arr_size)
{
  int* temp_arr = new int[arr_size];
  int new_temp_arr_size = arr_size;

  // Get odds from original array and store in temp array
  int odds_size = 0;
  for (int i = 0; i < arr_size; i++)
  {
    if (arr[i] % 2 != 0)
    {
      temp_arr[odds_size] = arr[i];
      odds_size++;
    }
  }

  // Get evens from original array and store in temp array
  int evens_size = arr_size - 1;
  for (int i = evens_size; i >= 0; i--)
  {
    if (arr[i] % 2 == 0)
    {
      temp_arr[evens_size] = arr[i];
      evens_size--;
    }
  }

  // Store values from temp array into original arr
  for (int i = 0; i < arr_size; i++)
  {
    arr[i] = temp_arr[i];
  }

  delete [] temp_arr;  // Free up memory allocation
  temp_arr = arr;  // Reset temp pointer back to original arr
}

void print_array(int arr[], int arr_size)
{
  for (int i = 0; i < arr_size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}