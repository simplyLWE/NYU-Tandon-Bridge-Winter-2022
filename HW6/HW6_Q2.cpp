/* 

Assignment:
-----------

Write a program that, prints a 'pine tree' consisting of triangles of increasing sizes, filled with a character (eg. '*' or '+' or '$', etc).

Your program should interact with the user to read the number of triangles in the tree and the character filling the tree.

Your implementation should include the following functions:

a. void printShiftedTriangle(int n, int m, char symbol)
    It prints an n-line triangle, filled with symbol characters, shifted m spaces from the left margin.
    
    For example, if we call printShiftedTriangle(3, 4, +), the expected output is:
      + 
     +++
    +++++

b. void printPineTree(int n, char symbol)
    It prints a sequence of n triangles of increasing sizes (the smallest triangle is a 2-line triangle), which form the shape of a pine tree.
    The triangles are filled with the symbol character.

    For example, if we call printPineTree(3, #), the expected output is:
        #
       ###
        #
       ###
      #####
        #
       ###
      #####
     #######

*/

#include <iostream>
using namespace std;

// Function Prototypes
void print_shifted_triangle(int triangle_size, int shift, char symbol);
void print_pinetree(int pinetree_size, char symbol);

int main()
{
  // Prompt user
  int pinetree_size = 0;
  char symbol = '\0';
  do
  {
    cout << "Please enter size of the pinetree: ";
    cin >> pinetree_size;
  }
  while(pinetree_size <= 0);
  cout << "Please enter character symbol: ";
  cin >> symbol;

  // Print out user-specified pinetree
  print_pinetree(pinetree_size, symbol);

  return 0;
}

// Prints pinetree of triangles of increasing size
void print_pinetree(int pinetree_size, char symbol)
{
  int triangle_size = 2;  // Smallest size is 2
  int shift = pinetree_size - 1;
  int repeat = 0;
  do
  {
    print_shifted_triangle(triangle_size, shift, symbol);
    triangle_size++;
    shift--;
    repeat++;
  }
  while(repeat < pinetree_size);
}

// Prints one triangle
void print_shifted_triangle(int triangle_size, int shift, char symbol)
{
  // Create right aligned triangle
  for (int h = 1; h <= triangle_size; h++)
  {
    for (int r = 1; r <= (triangle_size - h) + shift; r++)
    {
      cout << ' ';
    }
    for (int r = 1; r < h; r++)
    {
      cout << symbol;
    }
    cout << symbol; // Join right to left
    // Create left aligned triangle
    for (int r = 1; r < h; r++)
    {
      cout << symbol;
    }
  cout << endl;
  }
}