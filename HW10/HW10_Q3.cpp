/*

Assignment:
-----------

In this question, you will write two versions of a program that reads from the user a sequence of positive integers ending with -1,
and another positive integer num that the user wishes to search for.

The program should then print all the line numbers in sequence entered by the user, that contain num,
or a message saying that num does not show at all in the sequence.

Your program should interact with the user exactly as it shows in the following example:

Please enter a sequence of positive integers, each in a separate line. End you input by typing -1.
13
5
8
2
9
5
8
8
-1
Please enter a number you want to search. 5
5 shows in lines 2, 6.

a) The first version of the program, is not allowed to use the vector data structure.
b) The second version of the program, should use the vector data structure.

Implementation requirements (for both programs):
1. Think how to break down your implementation to functions.
2. Your programs should run in linear time. That is, if there are n numbers in the input sequence, your program should run in 𝜃(n).
3. Write the two programs in two functions named main1() and main2(). Also have the main() test these two functions.

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> main2();
int* main1(int& arr_size);

const int END = -1;

int main()
{
  /*-----SECTION A: USING POINTER TO HEAP DYNAMIC ARRAY DATA STRUCTURE-----*/
  // Get array of positive integers
  int* pos_ints_arr = NULL;
  int pos_ints_arr_size = 0;
  pos_ints_arr = main1(pos_ints_arr_size);

  // Prompt user for a number to search
  int search_num_a = 0;
  cout << "Please enter a number you want to search: ";
  cin >> search_num_a;
  cout << "The number " << search_num_a << " apears in lines: " << endl;

  // Iterate through array to find number
  int zero_index_a = 1;
  for (int i = 0; i < pos_ints_arr_size; i++)
  {
    if (pos_ints_arr[i] == search_num_a)
    {
      cout << i + zero_index_a << " ";
    }
  }
  cout << endl;

  // Free up memory allocation
  delete [] pos_ints_arr;
  pos_ints_arr = NULL;
  
  /*-----SECTION A: USING POINTER TO HEAP DYNAMIC ARRAY DATA STRUCTURE-----*/
  

  
  /*-----SECTION B: USING VECTOR DATA STRUCTURE:-----*/
  // Get vector of positive integers
  vector<int> pos_ints = main2();
  int size = pos_ints.size();
  
  // Prompt user for a number to search
  int search_num_b = 0;
  cout << "Please enter a number you want to search: ";
  cin >> search_num_b;
  cout << "The number " << search_num_b << " apears in lines: " << endl;

  // Iterate through vector to find number
  int zero_index_b = 1;
  for (int i = 0; i < size; i++)
  {
    if (pos_ints[i] == search_num_b)
    {
      cout << i + zero_index_b << " ";
    }     
  }
  cout << endl;
  /*-----SECTION B: USING VECTOR DATA STRUCTURE:-----*/
  
  return 0;
}

// Returns pointer to heap dynamic array
int* main1(int& arr_size)
{
  cout << "-------------------------------------------------------------- " << endl;
  cout << "SECTION A: USING POINTER TO HEAP DYNAMIC ARRAY DATA STRUCTURE: " << endl;
  cout << "-------------------------------------------------------------- " << endl;
  
  int nums_arr_size = arr_size;
  int* nums_arr = new int[nums_arr_size];

  // Prompt user to input sequence of positive integers
  cout <<  "Please enter a sequence of positive integers,"
  << " each in a separate line." << endl;
  cout << "End input by typing -1." << endl;

  // Read values into heap dynamic array
  int num = 0;
  bool end_input = false;
  while (end_input == false)
  {
    cin >> num;
    if (num == END)
    {
      end_input = true;
    }
    else
    {
      nums_arr[nums_arr_size] = num;
      nums_arr_size++;
    }
  }
  // Update array size to pass by reference back into main
  arr_size = nums_arr_size;
  return nums_arr;
}

// Returns vector
vector<int> main2()
{
  cout << "----------------------------------------" << endl;
  cout << "SECTION B: USING VECTOR DATA STRUCTURE: " << endl;
  cout << "----------------------------------------" << endl;
  int num = 0;
  vector<int> nums;
  
  // Prompt user to input sequence of positive integers
  cout <<  "Please enter a sequence of positive integers,"
  << " each in a separate line." << endl;
  cout << "End input by typing -1." << endl;
  
  // Read values into vector
  bool end_input = false;
  while (end_input == false)
  {
    cin >> num;
    if (num == END)
    {
      end_input = true;
    }
    else
    {
      nums.push_back(num);
    }
  }
  return nums;
}