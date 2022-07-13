/*

Assignment:
-----------

Define the following constants:
const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

Write a program that asks the user to enter a Real number,
then it asks the user to enter the method by which they want to round that number (floor, ceiling or to the nearest integer).
The program will then print the rounded result.

Your program should interact with the user exactly as it shows in the following example:

Please enter a Real number: 4.78
Choose your rounding method:
1. Floor round
2. Ceiling round
3. Round to the nearest whole number
2
5

Implementation requirements:
1. Use a switch statement.
2. You are not allowed to include and use the math library.

*/

#include <iostream>
using namespace std;

// Constants for switch cases
const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main()
{
  // Vars for user input
  float num = 0;
  int option = 0;

  // Prompt user for number
  cout << "Please enter a real number: ";
  cin >> num;

  // Formatting
  cout << endl;

  // Prompt user for rounding method
  cout << "Choose your rounding method:" << endl;
  cout << "1. Floor round" << endl;
  cout << "2. Ceiling round" << endl;
  cout << "3. Round to the nearest whole number" << endl;
  cout << endl; // Formatting
  cin >> option;

  // Reprompt user if invalid input
  if (option < 1 || option > 3)
  {
    cout << endl; // Formatting
    cout << "Invalid option. Please enter 1, 2, or 3: ";
    cin >> option;
  }

  // Implement rounding function
  switch (option)
  {
    // Rounds num down, returning the largest integral value that is not greater than num
    case FLOOR_ROUND:
      // Handle positive
      if (num >= 0)
      {
        cout << (int) num << endl;
      }
      // Handle negative
      else if (num < 0)
      {
        cout << (int)(num - 1) << endl;
      }

      break;

    // Rounds num up, returning the smallest integral values that is not less than num
    case CEILING_ROUND:
      if (num >= 0)
      {
        cout << (int)(num + 1) << endl;
      }
      // Handle negative
      else if (num < 0)
      {
        cout << (int) num << endl;
      }
      break;

    // Returns the integral value that is nearest to num, with halfway cases rounded away from zero
    case ROUND:
      // Handle positive
      if (num >= 0)
      {
        cout << (int)(num + 0.5) << endl;
      }
      // Handle negative
      else if (num < 0)
      {
        cout << (int)(num - 0.5) << endl;
      }
      break;
  }

  return 0;
} 