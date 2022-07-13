/*

Assignment:
-----------

a. Implement a function:
  void printDivisors(int num)

  This function is given a positive integer num, and prints all of num’s divisors in an ascending order, separated by a space.

  For example, if we call printDivisors(100), the expected output is:
  1 2 4 5 10 20 25 50 100

  Implementation requirement: Pay attention to the running time of your function.
  An efficient implementation would run in Θ(√𝑛𝑢𝑚).

b. Use the function above when implementing a program that reads from the user a positive integer (≥2), and prints all it’s divisors.
  
  Your program should interact with the user exactly as it shows in the following example:
  
  Please enter a positive integer >= 2: 100
  1 2 4 5 10 20 25 50 100
 
*/

#include <iostream>
#include <cmath>
using namespace std;

// Function prototype
void print_divisors(int num);

int main()
{
  // Prompt user for positive integer
  int num = 0;
  do
  {
    cout << "Please enter a positive integer >= 2: ";
    cin >> num;
  }
  while (num < 2);
  
  // Print corresponding divisors 
  print_divisors(num);

  // Formatting
  cout << endl;
  
  return 0;
}

// An efficient implementation: O(sqrt(n))
void print_divisors(int num)
{
  for (int i = 1; i <= sqrt(num); i++)
  {
    if (num % i == 0)
    {
      cout << i << " ";
    }
  }
  for (int i = sqrt(num); i > 0; i--)
  {
    if (num % i == 0)
    {
      if (i * i != num) // Account for duplicates
      {
        cout << num / i << " "; 
      }
    }
  }
}