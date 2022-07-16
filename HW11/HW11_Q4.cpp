/*

Assignment:
-----------

(Take from Ch14 problem 6 in text):

The game of "Jump It" consists of a board with n positive integers in a row,
except for the first column, which always contains zero.
These numbers represent the cost to enter each column.

Here is a sample game board where n is 6:
[ 0 | 3 | 80 | 6 | 57 | 10 ]

The object of the game is to move from the first column to the last column with the lowest total cost.
            
The number in each column represents the cost to enter that column.
You always start the game in the first column and have two types of moves.
You can either move to the adjacent column or jump over the adjacent column to land two columns over.
The cost of a game is the sum of the costs of the visited columns.
In the board shown above, there are several ways to get to the end.
Starting in the first column, our cost so far is 0.
We could jump to 80, then jump to 57, and then move to 10 for a total cost of 80 + 57 + 10 = 147.
However, a cheaper path would be to move to 3, jump to 6, then jump to 10, for a total cost of 3 + 6 + 10 = 19.

Write a recursive function that solves this problem
and returns the lowest cost of a game board represented and passed as an array.

Note: your function shouldn’t output the actual sequence of jumps, only the lowest cost of this sequence.

*/

#include <iostream>
using namespace std;

int jump_it(int board[], int size, int jump);
void print_board(int arr[], int size);

/*
TO-DO
[ ] Fix logic to calculate cheaper jump paths
*/

int main()
{
  // Board setup
  int board[] = {0, 3, 80, 6, 57, 10};
  int size = sizeof(board)/sizeof(int);
  int jump = 0;  // Start jump at 0
  print_board(board, size);

  // Find lowest cost path
  int jump_cost = jump_it(board, size - 1, jump);
  cout << "The sum of the lowest cost of jumps is " << jump_cost << endl;
    
  return 0;
}

int jump_it(int board[], int size, int jump)
{
  // Base Case
  if (size == jump)
  {
    return board[jump];
  } 
  else if (size - 1 == jump)
  {
    return (board[0] + board[size]);
  }
  // Recursive Case
  else if (jump_it(board, size, jump + 1) < jump_it(board, size, jump + 2))
  {
    return (board[jump] + jump_it(board, size, jump + 1));
  }
  else
  {
    return (board[jump] + jump_it(board, size, jump + 2));
  }
}

void print_board(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}