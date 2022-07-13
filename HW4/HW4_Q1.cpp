/*

Assignment:
-----------

Write two versions of a program that reads a positive integer n, and prints the first n even numbers.
a) In the first, use a while loop.
b) In the second, use a for loop.

Each section should interact with the user exactly as it shows in the following example:

Please enter a positive integer: 3
2
4
6

*/

#include <iostream>
using namespace std;

int main()
{
  // Var for user input
  int num = 0;

  // Prompt user for positive integer
  do
  {
    cout << "Please enter a positive integer: ";
    cin >> num;
  }
  while (num <= 0);

  // Formatting
  cout << endl;
  cout << "Section (a): While-loop implementation:" << endl;

  // While-loop implementation
  int even_while = 0; // Starting value for calculating even num
  int count = 0;
  while (count < num)
  {
    even_while += 2;
    cout << even_while << endl;
    count ++;
  }

  // Formatting
  cout << endl;
  cout << "Section (b): For-loop implementation:" << endl;

  // For-loop implementation
  int even_for = 0; // Starting value for calculating even num
  for (int i = 0; i < num; i++)
  {
    even_for += 2;
    cout << even_for << endl;
  }

  return 0;
}