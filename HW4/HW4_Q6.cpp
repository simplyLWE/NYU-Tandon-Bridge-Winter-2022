/*

Assignment:
-----------

Write a program that asks the user to input a positive integer n,
and print all of the numbers from 1 to n that have more even digits than odd digits.

For example, if n = 30, the program should print:
2
4
6
8
20
22
24
26
28

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

  // Iterate through the range of nums
  // Start count at 1: 0 is non-positive
  for (int i = 1; i <= num; i++)
  {
    // Find the even nums
    if (i % 2 == 0)
    {
      // Vars for number of even and odd digits in num
      int even_digit = 0;
      int odd_digit = 0;

      // Loop through all digits in num to count evens and odds
      int temp_num = i; // Preserve i
      int curr_digit = 0;
      bool stop_digit_count = false;
      while (stop_digit_count == false)
      {
        curr_digit = temp_num % 10;
        if (curr_digit % 2 == 0)
        {
          even_digit++;
        }
        else
        {
          odd_digit++;
        }
        temp_num = temp_num / 10;
        if (temp_num == 0)
        {
          stop_digit_count = true;
        }
      }
      // Print nums that have more even digits
      if (even_digit > odd_digit)
      {
        cout << i << endl;
      }
    }
  }
  return 0;
}