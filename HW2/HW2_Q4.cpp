/* 

Assignment:
-----------

Write a program that reads from the user two positive integers,
and prints the result of when we add, subtract multiply, divide, div and mod them.

Your program should interact with the user exactly as it shows in the following example:

Please enter two positive integers, separated by a space: 14 4

14 + 4 = 18
14 – 4 = 10
14 * 4 = 56
14 / 4 = 3.5
14 div 4 = 3
14 mod 4 = 2

*/

#include <iostream>
using namespace std;

int main()
{
  // Vars for user input
  int num1 = 0;
  int num2 = 0;

  // Get integers from user
  cout << "Please enter two positive integers, separated by a space:" << endl;
  cin >> num1 >> num2;

  // Add
  int user_add = num1 + num2;
  cout << num1 << " + " << num2 << " = " << user_add << endl;

  // Subtract
  int user_sub = num1 - num2;
  cout << num1 << " - " << num2 << " = " << user_sub << endl;

  // Multiply
  int user_mult = num1 * num2;
  cout << num1 << " * " << num2 << " = " << user_mult << endl;

  // Divide
  float user_divide = (float)num1 / (float)num2;
  cout << num1 << " / " << num2 << " = " << user_divide << endl;

  // Div
  int user_div = num1 / num2;
  cout << num1 << " div " << num2 << " = " << user_div << endl;
  
  // Mod
  int user_mod = num1 % num2;
  cout << num1 << " mod " << num2 << " = " << user_mod << endl;

  return 0;
}