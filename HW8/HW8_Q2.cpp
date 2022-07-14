/*

Assignment:
-----------

A palindrome is a word, which reads the same backward or forward.
For example, noon, civic, radar, level, rotor, kayak, reviver, racecar, redder, madam, and refer are all palindromes.

a. Implement a function: bool isPalindrome(string str)
    This function is given a string str containing a word, and returns true if and only if str is a palindrome.

b. Implement following functions:
    Write a program that reads a word from the user and announces to the user if it is a palindrome or not.
    
    Your program should interact with the user exactly as it shows in the following example:
    
    Please enter a word: level
    level is a palindrome

*/

#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
bool is_palindrome(string str);

int main()
{
  // Get word from user
  // Assumes string input is lower-case
  string word = "";
  cout << "Please enter a word: ";
  cin >> word;

  // Check if word is palindrome
  if (is_palindrome(word))
  {
    cout << word << " is a palindrome" << endl;
  }
  else
  {
    cout << word << " is NOT a palindrome" << endl;
  }

  return 0;
}

bool is_palindrome(string str)
{
  int str_length = str.length();  // Set length of string
  bool palindrome = false;
  
  // Iterate over string to get chars
  // Divide str_length by 2, more efficient
  // Prevents unnecessary double counting
  bool not_palindrome = true;  // Break out of loop
  for (int i = 0; i < str_length / 2; i++)
  {
    // Is first char same as last?
    if(str[i] != str[str_length - 1 - i])
    {
      not_palindrome = false;
    }
    else
    {
      palindrome = true;
    }
  }

  if (palindrome)
  {
    return true;
  }
  else
  {
    return false;
  }
}