/* 

Assignment:
-----------

Write a program that reads from the user a positive integer (in a decimal representation), and prints its binary (base 2) representation.

Your program should interact with the user exactly as it shows in the following example:

Enter decimal number:
76
The binary representation of 76 is 1001100

Implementation Requirements:
1. You are supposed to implement the algorithm that converts to base 2. You should not use any string or special cout functionalities to make the conversion.
2. You are not allowed to use arrays.

*/

#include <iostream>
using namespace std;

int main()
{
  // Var for user input
  int decimal_num = 0;

  // Prompt user for positive integer
  do
  {
    cout << "Enter decimal number: ";
    cin >> decimal_num; 
  }
  while (decimal_num <= 0);

  // Preserve original decimal number
  int orig_decimal = decimal_num;

  // Convert decimal number to binary
  int binary_num = 0;
  string binary_str = "";
  
  while (decimal_num > 0)
  {
    binary_num = decimal_num % 2;
    if (binary_num == 0)
    {
      binary_str = '0' + binary_str;
    }
    else if (binary_num == 1)
    {
      binary_str = '1' + binary_str;
    }
    decimal_num = decimal_num / 2;        
  }

  // Print results of conversion
  cout << "The binary representation of "
  << orig_decimal << " is " << binary_str << endl;

  return 0;
}