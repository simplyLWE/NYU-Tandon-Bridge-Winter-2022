/*

Assignment:
-----------

The Fibonacci numbers sequence, Fn, is defined as follows:
F1 is 1, F2 is 1, and Fn = Fn-1 + Fn-2 for n = 3, 4, 5, ...

In other words, each number is the sum of the previous two numbers.
The first 10 numbers in Fibonacci sequence are: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55

Note:
Background of Fibonacci sequence: https://en.wikipedia.org/wiki/Fibonacci_number

1. Write a function int fib(int n) that returns the n-th element of the Fibonacci sequence.
2. Write a program that prompts the user to enter a positive integer num, and then prints the num’s elements in the Fibonacci sequence.

Your program should interact with the user exactly as it shows in the following example:

Please enter a positive integer: 7
13

*/

#include <iostream>
using namespace std;

// Function Prototype
int fib(int num);

// Note: A user input cannot be larger than 46, otherwise this will result in an incorrect fibonacci number, due to the storage size of an int value.
// Anything larger than 46 returns a value larger than 2^32
int const MAX_FIB_NUM = 46; 

int main()
{
  // Prompt user for positive integer
  int num = 0;
  do
  {
    cout << "Please enter a positive integer: ";
    cin >> num;
  }
  while(num <= 0 || num > MAX_FIB_NUM);

  // Print corresponding fibonacci number
  int fibonacci_num = fib(num);
  cout << fibonacci_num << endl;

  return 0;
}

int fib(int num)
{
  // Init first two fib nums according to first two sequence values
  int f1 = 1;
  int f2 = 1;
  int fib_num = 0;

  for (int i = 1; i <= num; i++)
  {
    if (i == 1) // First fibonacci number is 1
    {
      fib_num = f1;
    }
    else if (i == 2) // Second fibonacci number is 1
    {
      fib_num = f2;
    }
    else // Remaining fibonacci numbers are sum of previous two
    {
      fib_num = f1 + f2;
      f1 = f2;
      f2 = fib_num;
    }
  }
  return fib_num;
}