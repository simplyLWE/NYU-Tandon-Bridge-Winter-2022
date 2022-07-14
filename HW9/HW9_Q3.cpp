/*

Assignment:
-----------

In this question, you will write four versions of a function getPosNums that gets an array of integers arr, and its logical size.
When called it creates a new array containing only the positive numbers from arr.
For example, if arr = [3, -1, -3, 0, 6, 4], the functions should create an array containing the following 3 elements: [3, 6, 4]

The four versions you should implement differ in the way the output is returned.
The prototypes of the functions are:

a. int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)
   returns the base address of the array (containing the positive numbers),
   and updates the output parameter outPosArrSize with the array’s logical size.

b. int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr)
   returns the base address of the array (containing the positive numbers),
   and uses the pointer outPosArrSizePtr to update the array’s logical size.

c. void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize)
   updates the output parameter outPosArr with the base address of the array (containing the positive numbers),
   and the output parameter outPosArrSize with the array’s logical size.

d. void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr)
   uses the pointer outPosArrPtr to update the base address of the array (containing the positive numbers),
   and the pointer outPosArrSizePtr to update the array’s logical size.

Note: You should also write a main program that calls and tests all these functions.

*/

#include <iostream>
using namespace std;

void print_arr(int *arr, int arr_size);
int *pos_ints_a(int *arr, int arr_size, int &update_new_arr_size);
int *pos_ints_b(int *arr, int arrSize, int *update_new_arr_size);
void pos_ints_c(int *arr, int arr_size, int *&update_new_arr, int &update_new_arr_size);
void pos_ints_d(int *arr, int arr_size, int **update_new_arr, int *update_new_arr_size);

int main()
{
  // Original array allocated on the stack
  int orig_arr[6] = {3, -1, -3, 0, 6, 4};
  int orig_arr_size = 6;

  //------------------------Section A------------------------------//
  // Pointer to new array and size will be updated by function call
  int *a_arr = NULL;
  int a_arr_size = 0;
  cout << "------------SECTION A------------" << endl;
  a_arr = pos_ints_a(orig_arr, orig_arr_size, a_arr_size);
  print_arr(a_arr, a_arr_size);
  delete a_arr; // Free up allocated memory
  //------------------------Section A------------------------------//

  cout << endl;

  //------------------------Section B------------------------------//
  // Pointer to new array and size will be updated by function call
  int *b_arr = NULL;
  int b_arr_size = 0; // Value of new size arr
  int *ptr_b_arr_size = &b_arr_size; // Pointer to memory address of new size array
  cout << "------------SECTION B------------" << endl;
  b_arr = pos_ints_b(orig_arr, orig_arr_size, ptr_b_arr_size);
  print_arr(b_arr, b_arr_size);
  delete b_arr; // Free up allocated memory
  //------------------------Section B------------------------------//

  cout << endl;

  //------------------------Section C------------------------------//
  // Pointer and size will be updated as pass-by-reference during function call
  int *c_arr = NULL;
  int c_arr_size = 0;
  cout << "------------SECTION C------------" << endl;
  pos_ints_c(orig_arr, orig_arr_size, c_arr, c_arr_size);
  print_arr(c_arr, c_arr_size);
  delete c_arr; // Free up allocated memory
  //------------------------Section C------------------------------//

  cout << endl;

  //------------------------Section D------------------------------//
  // Pointer and size will be updated by pointers during function call;
  int *d_arr = NULL;
  int **ptr_d_arr = &d_arr;
  int d_arr_size = 0; // Value of new size arr
  int *ptr_d_arr_size = &d_arr_size;  // Pointer to memory address of new size array
  cout << "------------SECTION D------------" << endl;
  pos_ints_d(orig_arr, orig_arr_size, ptr_d_arr, ptr_d_arr_size);
  print_arr(d_arr, d_arr_size);
  delete d_arr; // Free up allocated memory
  //------------------------Section D------------------------------//

  return 0;
}

//----------------------Section D Function----------------------------//
// Creates a new array on the heap
// Uses the new array pointer to point back to main and update the pointer
// Uses the pointer to the new array size to update the size
void pos_ints_d(int *arr, int arr_size, int **update_new_arr, int *update_new_arr_size)
{
  // Dereference pointer to get value of size of array
  int new_arr_size = *update_new_arr_size;
  
  // Get positive ints from original array
  for (int i = 0; i < arr_size; i++)
  {
    if (arr[i] > 0)
    {
      new_arr_size++;
    }
  }

  int* new_arr = *update_new_arr; // Dereference double pointer to create pointer to heap array
  new_arr = new int[new_arr_size]; // Set pointer to new array on heap
  
  *update_new_arr = new_arr;  // Update pointer to point to new array
  *update_new_arr_size = new_arr_size; // Update value of pointer to new array size

  // Copy all values from original array onto new heap array
  int j = 0; // Init values for new array
  for (int i = 0; i < arr_size; i++)
  {
    if (arr[i] > 0)
    {
      new_arr[j] = arr[i];
      j++;
    }
  }
}
//----------------------Section D Function----------------------------//


//----------------------Section C Function----------------------------//
// Creates a new array on the heap
// Updates the new array as a pass-by-reference using pointer
// Updates the size of the new array as a pass-by-reference
void pos_ints_c(int *arr, int arr_size, int *&update_new_arr, int &update_new_arr_size)
{
  int new_arr_size = 0;
  // Get positive ints from original array
  for (int i = 0; i < arr_size; i++)
  {
    if (arr[i] > 0)
    {
      new_arr_size++;
    }
  }

  int *new_arr = new int[new_arr_size]; // Create ptr to new array on heap
  update_new_arr = new_arr;             // Update pointer in place
  update_new_arr_size = new_arr_size;   // Update new array size in place

  // Copy all values from original array onto new heap array
  int j = 0; // Init values for new array
  for (int i = 0; i < arr_size; i++)
  {
    if (arr[i] > 0)
    {
      new_arr[j] = arr[i];
      j++;
    }
  }
}
//----------------------Section C Function----------------------------//


//----------------------Section B Function----------------------------//
// Creates a new array on the heap and returns a pointer to that array
// Uses the pointer to the new array size to update the size
int *pos_ints_b(int *arr, int arr_size, int *update_new_arr_size)
{
  // Dereference pointer to get value of size of array
  int new_arr_size = *update_new_arr_size;

  // Get positive ints from original array
  for (int i = 0; i < arr_size; i++)
  {
    if (arr[i] > 0)
    {
      new_arr_size++;
    }
  }

  int *new_arr = new int[new_arr_size]; // Create ptr to new array on heap
  *update_new_arr_size = new_arr_size; // Update value of pointer to new array size

  // Copy all values from original array onto new heap array
  int j = 0; // Init values for new array
  for (int i = 0; i < arr_size; i++)
  {
    if (arr[i] > 0)
    {
      new_arr[j] = arr[i];
      j++;
    }
  }
  return new_arr;
}
//----------------------Section B Function----------------------------//


//----------------------Section A Function----------------------------//
// Creates a new array on the heap and returns a pointer to that array
// Updates the size of the new array as a pass-by-reference
int *pos_ints_a(int *arr, int arr_size, int &update_new_arr_size)
{
  int new_arr_size = 0;
  // Get positive ints from original array
  for (int i = 0; i < arr_size; i++)
  {
    if (arr[i] > 0)
    {
      new_arr_size++;
    }
  }

  int *new_arr = new int[new_arr_size]; // Create ptr to new array on heap
  update_new_arr_size = new_arr_size;   // Update new array size in place

  // Copy all values from original array onto new heap array
  int j = 0; // Init values for new array
  for (int i = 0; i < arr_size; i++)
  {
    if (arr[i] > 0)
    {
      new_arr[j] = arr[i];
      j++;
    }
  }
  return new_arr;
}
//----------------------Section A Function----------------------------//


void print_arr(int *arr, int arr_size)
{
  cout << "New Heap Array of Positive Ints: " << endl;
  for (int i = 0; i < arr_size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}