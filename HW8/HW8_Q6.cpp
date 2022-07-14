/*

Assignment:
-----------

Write a program that reads in a line of text
and outputs the line with all the digits in all integer numbers replaced with 'x'.

Please enter a line of text:
My userID is john17 and my 4 digit pin is 1234 which is secret
My userID is john17 and my x digit pin is xxxx which is secret

Notes:
1. If a digits is part of a word, then the digit is not changed to an 'x'.
    For example, john17 is NOT changed to johnxx.
2. You may assume that the text entered by the user will contain only letters (upper case or lower case), digits and spaces.
3. Think how to break down your implementation to functions.

*/

#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
bool is_digit(char char1);
void mask_digits(string& str, int str_size);

const char EMPTY_SPACE = ' ';
const char MASKED_CHAR = '*';

int main()
{
  // Get user input
  string user_input = "";
  cout << "Please enter a line of text: " << endl;
  getline(cin, user_input);

  // Set length of user's string
  int string_length = user_input.length();

  // Mask digits in user's string
  mask_digits(user_input, string_length);

  // Print masked results
  cout << user_input;
  cout << endl;
  return 0;
}

// Mask string in place
void mask_digits(string& str, int str_size)
{
  // Iterate over string to get chars
  for (int i = 0; i <= str_size; i++)
  {
    // Check if char is a digit
    if (is_digit(str[i]))
    {
      // Is digit isolated?
      if (str[i-1] == EMPTY_SPACE && (str[i+1] == EMPTY_SPACE))
      {
        str[i] = MASKED_CHAR;
      }
      
      // Is digit part of mask?
      if (str[i-1] == EMPTY_SPACE || str[i-1] == MASKED_CHAR)
      {
        str[i] = MASKED_CHAR;;
      }
    }
  }
}

// Determines if char is a digit
bool is_digit(char char1)
{
  if (char1 >= '0' && char1 <= '9')
  {
    return true; // Char is a digit
  }
  else
  {
    return false;  // Char is not a digit
  }
}