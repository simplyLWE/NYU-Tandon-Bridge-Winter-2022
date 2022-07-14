/* 

Assignment:
-----------

Implement following functions:

a. void reverseArray(int arr[], int arrSize)
    That takes arr, an array of integers, and its size, arrSize.
    When called, it reorders the elements of the array to appear in reverse order.

    For example, if arr is an array containing [1, 2, 3, 4], after calling reverseArray, arr will look like: [4, 3, 2, 1].

b. void removeOdd(int arr[], int& arrSize)
    That takes arr, an array of integers, and its size, arrSize.
    When called, the function alters arr so that the only numbers in it at the end are the even ones,
    which should remain in their original relative order.
    Additionally, the function updates arrSize so it contains the new logical size of the array after removing the odd numbers
    (note that arrSize is a parameter used both for input and output).

    For example, if arr is an array containing [1, 2, 3, 4], after calling removeOdd, arr will look like: [2, 4],
    and the parameter arrSize will update to 2. Notice the values in arr[2] and arr[3] are discarded.

c. void splitParity(int arr[],int arrSize)
    That takes arr, an array of integers, and its size, arrSize.
    When called, the function changes the order of numbers in arr so that all the odd numbers will appear first,
    and all the even numbers will appear last.
    Note that the inner order of the odd numbers and the inner order of the even numbers don’t matter.

    For example, if arr is an array containing [1, 2, 3, 4], after calling splitParity, arr could look like: [3, 1, 2, 4].

Implementation requirements:
1. In all three functions, you are not allowed to use an auxiliary array (a temporary local array).
2. Pay attention to the running time of your functions.
   For each one of the functions above, an efficient implementation would run in a linear time (that is Θ(𝑎𝑟𝑟𝑆𝑖𝑧𝑒)).

Note: You don’t have to submit a main function for this question. You may use the following program to test your functions:

#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize);

int main() {
  int arr1[10] = {9, 2, 14, 12, -3};
  int arr1Size = 5;

  int arr2[10] = {21, 12, 6, 7, 14};
  int arr2Size = 5;

  int arr3[10] = {3, 6, 4, 1, 12};
  int arr3Size = 5;

  reverseArray(arr1, arr1Size);
  printArray(arr1, arr1Size);

  removeOdd(arr2, arr2Size);
  printArray(arr2, arr2Size);

  splitParity(arr3, arr3Size);
  printArray(arr3, arr3Size);

return 0;
}

void printArray(int arr[], int arrSize){
  int i;
  for (i = 0; i < arrSize; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

When running this program you should expect the following output (the output for splitParity could be different):
-3 12 14 2 9
12 6 14
1 3 6 4 12

*/

#include <iostream>
using namespace std;

// Function Prototypes
void print_array(int arr[], int arr_size);
void reverse_array(int arr[], int arr_size);
void remove_odd(int arr[], int& arrSize);
void split_parity(int arr[], int arr_size);
void swap_value(int &a, int &b);

int main()
{
  // Array 1 (Partially filled)
  int arr1[10] = {9, 2, 14, 12, -3};
  int arr1Size = 5;
  // Array 2 (Partially filled)
  int arr2[10] = {21, 12, 6, 7, 14};
  int arr2Size = 5;
  // Array 3 (Partially filled)
  int arr3[10] = {3, 6, 4, 1, 12};
  int arr3Size = 5;
  
  //----------REVERSE ARRAY FUNCTION----------//
  // cout << "TESTING REVERSE ARRAY FUNCTION..." << endl;
  // cout << "First array test case: " << endl;
  // reverse_array(arr1, arr1Size);
  // print_array(arr1, arr1Size);
  // cout << "Second array test case: " << endl;
  // reverse_array(arr2, arr2Size);
  // print_array(arr2, arr2Size);
  // cout << "Third array test case: " << endl;
  // reverse_array(arr3, arr3Size);
  // print_array(arr3, arr3Size);
  //----------REVERSE ARRAY FUNCTION----------//
  
  //----------REMOVE ODD FUNCTION----------//
  // cout << "TESTING REMOVE ODD FUNCTION..." << endl;
  // cout << "First array test case: " << endl;
  // remove_odd(arr1, arr1Size);
  // print_array(arr1, arr1Size);
  // cout << "Second array test case: " << endl;
  // remove_odd(arr2, arr2Size);
  // print_array(arr2, arr2Size);
  // cout << "Third array test case: " << endl;
  // remove_odd(arr3, arr3Size);
  // print_array(arr3, arr3Size);
  //----------REMOVE ODD FUNCTION----------//

  //----------SPLIT PARITY ARRAY FUNCTION----------//
  // cout << "TESTING SPLIT PARITY FUNCTION..." << endl;
  // cout << "First array test case: " << endl;
  // split_parity(arr1, arr1Size);
  // print_array(arr1, arr1Size);
  // cout << "Second array test case: " << endl;
  // split_parity(arr2, arr2Size);
  // print_array(arr2, arr2Size);
  // cout << "Third array test case: " << endl;
  // split_parity(arr3, arr3Size);
  // print_array(arr3, arr3Size);
  //----------SPLIT PARITY ARRAY FUNCTION----------//
  
  cout << endl;
  return 0;
}

void reverse_array(int arr[], int arr_size)
{
  int end = arr_size - 1;
  int beg = 0;
  // Divide by 2, more efficient
  // Prevents unnecessary double counting
  for (int i = 0; i < arr_size / 2; i++)
  {
    beg = arr[i];
    arr[i] = arr[end];
    arr[end] = beg;
    end--;
    beg++;
  }
}

void remove_odd(int arr[], int& arr_size)
{
  int evens_size = 0;
  for (int i = 0; i < arr_size; i++)
  {
    if (arr[i] % 2 == 0)
    {
      arr[evens_size] = arr[i]; // Reset index
      evens_size++;
    }
  }
  arr_size = evens_size; // Update size
}

void split_parity(int arr[], int arr_size)
{
  int beg = 0;
  int end = arr_size - 1;

  // Compare chars from beginning and end approaching middle
  while (beg < end)
  {
    // If beginning char is even and end char is odd
    // Swap chars and approach middle
    if (arr[beg] % 2 == 0 && arr[end] % 2 != 0)
    {
      swap_value(arr[beg],arr[end]);
      beg++;
      end--;
    }
    // Otherwise check conditions and approach middle
    if (arr[beg] % 2 != 0) // If odd, leave as is, step in
    {
       beg++;
    }
    if (arr[end] % 2 == 0) // If even, leave as is, step in
    {
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

void print_array(int arr[], int arr_size)
{
  for (int i = 0; i < arr_size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}