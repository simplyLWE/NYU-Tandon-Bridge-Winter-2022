/*

Assignment:
-----------

Give a recursive implement to the following functions:

a. void printTriangle(int n)
    This function is given a positive integer n,
    and prints a textual image of a right triangle
    (aligned to the left) made of n lines with asterisks.

    For example, printTriangle(4), should print:
    *
    **
    ***
    ****

b. void printOppositeTriangles(int n)
    This function is given a positive integer n,
    and prints a textual image of a two opposite right triangles
    (aligned to the left) with asterisks, each containing n lines.
    
    For example, printOppositeTriangles(4), should print:
    ****
    ***
    **
    *
    *
    **
    ***
    ****

c. void printRuler(int n)
    This function is given a positive integer n, and prints a vertical ruler of 2^n − 1 lines.
    Each line contains '-' marks as follows:

    - The line in the middle (1/2) of the ruler contains n '-' marks
    - The lines at the middle of each half (1/4 and 3/4) of the ruler contains (n - 1) '-' marks
    - The lines at the 1/8, 3/8, 5/8, and 7/8 of the ruler contains (n - 2) '-' marks
    - And so on ...
    - The lines at the 1/2^k, 3/2^k, 5/2^k, ... , 2^k - 1 / 2^k of the ruler contains 1 '-' mark

    For example, printRuler(4), should print (only the blue marks):
    -
    --
    -
    ---
    -
    --
    -
    ----
    -
    --
    -
    ---
    -
    --
    -

    Hints:
    1. Take for n = 4: when finding print_ruler(4), try to think first what print_ruler(3) does,
       and how you can use it to print a ruler of size 4.
       Then, generally identify what print_ruler(n-1) is supposed to print, and use that
       in order to define how to print the ruler of size n.
    2. You may want to have more than one recursive call
    3. It looks much scarier than it actually is

*/

#include <iostream>
using namespace std;

void print_triangle(int n);
void print_opposite_triangles(int n);
void print_ruler(int n);

int main()
{
  int n = 4;

  cout << "SECTION A:" << endl;
  print_triangle(n);
  cout << endl;
  
  cout << "SECTION B:" << endl;
  print_opposite_triangles(n);
  cout << endl;
  
  cout << "SECTION C:" << endl;
  print_ruler(n);

  return 0;
}

//SECTION C
void print_ruler(int n)
{
  // Base Case
  if (n == 0)
  {
    return;
  }
  // Recursive Case
  else
  {
    print_ruler(n - 1);
    for (int i = 0; i < n; i++)
    {
      cout << '-';
    }
    cout << endl;
    print_ruler(n - 1);
  }
}

// SECTION B
void print_opposite_triangles(int n)
{
  // Base Case
  if (n == 0)
  {
    return;
  }
  // Recursive Case
  else
  {
    // Top Half
    for (int i = 1; i <= n; i++)
    {
      cout << '*';
    }
    cout << endl;
    
    print_opposite_triangles(n - 1);
    
    // Bottom Half
    for (int i = 1; i <= n; i++)
    {
      cout << '*';
    }
    cout << endl;
  }
}

// SECTION A
void print_triangle(int n)
{ 
  // Base Case
  if (n == 0)
  {
    return;
  }
  // Recursive Case
  else
  {
    print_triangle(n - 1);
    for (int i = 1; i <= n; i++)
    {
      cout << '*';
    }
    cout << endl;
  }
}