/*

Assignment:
-----------

In this question we will use a simplified version of the Roman Numerals System to represent positive integers.

The digits in this system are I, V, X, L, C, D and M. Each digit corresponds to a decimal value, as showed in the following table:

Roman digit   | I | V | X  | L  |  C  |  D  |  M
--------------|---|---|----|----|-----|-----|-----
Decimal value | 1 | 5 | 10 | 50 | 100 | 500 | 1000

A number in the simplified Roman numerals system is a sequence of Roman digits, which follow these 2 rules:

1. The digits form a monotonically non-increasing sequence. That is the value of each digit is less than or equal to the value of the digit that came before it.
    For example, DLXXVI is a monotonically non-increasing sequence of Roman digits, but XIV is not.

2. There is no limit on the number of times that ‘M’ can appear in the number.
    ‘D’, ‘L’ and ‘V’ can each appear at most one time in the number.
    ‘C’, ‘X’ and ‘I’ can each appear at most four times in the number.

    For example: IIII, XVII and MMMMMMDCCLXXXXVII are legal numbers in our simplified Roman numeral system, but IIIII, XIV, VVI and CCXLIII are not.

Write a program that reads from the user a (decimal) number, and prints its representation in the simplified Roman numerals system.

Your program should interact with the user exactly as it shows in the following example:

Enter decimal number:
147
147 is CXXXXVII

*/

#include <iostream>
using namespace std;

// Constants for Roman Numeral Conversion
const int M = 1000;
const int D = 500;
const int C = 100;
const int L = 50;
const int X = 10;
const int V = 5;
const int I = 1;

int main()
{
  // Var for user input
  int decimal = 0;

  // Prompt user for positive integer
  do
  {
    cout << "Enter a decimal number: ";
    cin >> decimal;
  }
  while (decimal <= 0);

  // Display conversion while looping instead of after loop
  cout << decimal << " is ";
  
  // Convert decimal number to roman numeral
  int roman = 0;
  while (decimal > 0)
  {
    // Convert and print M
    roman = decimal / M;
    if (roman != 0)
    {
      for (int i = 0; i < roman; i++)
      {
        cout << 'M';
      }
    }
    decimal = decimal % M;

    // Convert and print D
    roman = decimal / D;
    if (roman != 0)
    {
      for (int i = 0; i < roman; i++)
      {
        cout << 'D';
      }
    }
    decimal = decimal % D;

    // Convert and print C
    roman = decimal / C;
    if (roman != 0)
    {
      for (int i = 0; i < roman; i++)
      {
        cout << 'C';
      }
    }
    decimal = decimal % C;

    // Convert and print L
    roman = decimal / L;
    if (roman != 0)
    {
      for (int i = 0; i < roman; i++)
      {
        cout << 'L';
      }
    }
    decimal = decimal % L;

    // Convert and print X
    roman = decimal / X;
    if (roman != 0)
    {
      for (int i = 0; i < roman; i++)
      {
        cout << 'X';
      }
    }
    decimal = decimal % X;
    
    // Convert and print V
    roman = decimal / V;
    if (roman != 0)
    {
      for (int i = 0; i < roman; i++)
      {
        cout << 'V';
      }
    }
    decimal = decimal % V;

    // Convert and print I
    roman = decimal / I;
    if (roman != 0)
    {
      for (int i = 0; i < roman; i++)
      {
        cout << 'I';
      }
    }
    decimal = decimal % I;
  }

  // Formatting
  cout << endl;

  return 0;
}