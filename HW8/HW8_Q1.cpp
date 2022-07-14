/*

Assignment:
-----------

1. Implement the function: int minInArray(int arr[], int arrSize)
    This function is given arr, an array of integers, and its logical size, arrSize.
    When called, it returns the minimum value in arr.

2. Write a program that reads from the user a sequence of 20 integers
   (unnecessarily different from one another) into an array,
   and outputs the minimum value, and all the indices it appears in the array.

    Your program should interact with the user exactly as it shows in the following example:
    
    Please enter 20 integers separated by a space:
    14 5 12 5 6 14 5 12 14 12 14 6 8 7 5 136 9 2189 10 6
    The minimum value is 5, and it is located in the following indices: 1 3 6 14

    Note: You may want to define additional functions for your program to use.

*/

#include <iostream>
using namespace std;

// Function Prototype
int get_min_value(int arr[], int arr_size);
void find_min_value_index(int arr[], int arr_size, int min);

const int MAX_INTS = 20;

int main()
{
  // Get and store integers from user
  int user_values [MAX_INTS];
  cout << "Please enter 20 integers separated by a space:" << endl;
  for (int i = 0; i < MAX_INTS; i++)
  {
    cin >> user_values[i];
  }
  cout << endl;

  // Determine min value
  int min_value = get_min_value(user_values, MAX_INTS);
  cout << "The minimum value is " << min_value;

  // Find index/indices of min value
  cout << ", and it is located at the following indices: " << endl;
  find_min_value_index(user_values, MAX_INTS, min_value);

  cout << endl;  // Clean Formatting

  return 0;
}

// Determine min value
int get_min_value(int arr[], int arr_size)
{
  int min_value = arr[0];
  for (int i = 0; i < MAX_INTS; i++)
  {
    if (arr[i] < min_value)
    {
      min_value = arr[i];
    }
  }
  return min_value;
}

// Print index of min values
void find_min_value_index(int arr[], int arr_size, int min)
{
  for (int i = 0; i < MAX_INTS; i++)
  {
    if (arr[i] == min)
    {
      cout << i << " ";
    }
  }
}