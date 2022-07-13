/*

Assignment:
-----------

Write a program that asks the user to input a positive integer n,
and prints a textual image of an hourglass made of 2n lines with asterisks.

For example if n = 4, the program should print:
*******
 *****
  ***
   * 
   *
  ***
 *****
*******

*/

#include <iostream>
using namespace std;

int main()
{
  // Var for user defined height
  int height = 0;

  // Prompt user for positive integer
  do
  {
    cout << "Enter height: ";
    cin >> height; 
  }
  while (height <= 0);
  
  // Create upside-down
  for (int h = 1; h <= height; h++) // Create height
  {
    // Left aligned pyramid
    for(int r = 1; r <= h - 1; r++) // Create row of empty spaces
    {
      cout << " ";
    }
    for (int r = 1; r <= height - h; r++)  // Create row of stars
    {
      cout << "*";
    }
    
    cout << "*";  // Create middle to align l. and r. pyramids
    
    // Right aligned pyramid
    for (int r = 1; r <= height - h; r++)  // Create row
    {
      cout << "*";
    }
    
    cout << endl; // Create a new line for height
  }

  // Create right-side up
  for (int h = 1; h <= height; h++) // Create height
  {
    // Left aligned pyramid
    for (int r = 1; r <= height - h; r++) // Create row of empty spaces
    {
      cout << " ";
    }
    for (int r = 1; r < h; r++) // Create row of stars
    {
      cout << "*";
    }

    cout << "*";  // Create middle to align l. and r. pyramids

    // Right aligned pyramid
    for (int r = 1; r < h; r++) // Create row
    {
      cout << "*";
    }
    cout << endl; // Create a new line for height
  }
  
  return 0;
}