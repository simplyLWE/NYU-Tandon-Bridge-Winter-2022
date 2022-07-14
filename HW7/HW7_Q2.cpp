/*

Assignment:
-----------

Consider the following definitions:

a. A proper divisor of a positive integer (≥ 2) is any of its divisors excluding the number itself.
    For example, the proper divisors of 10 are: 1, 2 and 5.

b. A perfect number is a positive integer (≥ 2) that is equal to the sum of its proper divisors.
    For example, 6 and 28 are perfect numbers, since:
    6 = 1 + 2 + 3
    28 = 1 + 2 + 4 + 7 + 14
   Background of perfect numbers: https://en.wikipedia.org/wiki/Perfect_number

c. Amicable numbers are two different positive integers (≥ 2),
   so related that the sum of the proper divisors of each is equal to the other number.
    For example, 220 and 284 are amicable numbers, since:
    284 = 1 + 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110 (proper divisors of 220)
    220 = 1 + 2 + 4 + 71 + 142 (proper divisors of 284)
   Background of amicable numbers: https://en.wikipedia.org/wiki/Amicable_numbers

a. Write a function:
    void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)

    The function takes as an input a positive integer num (≥ 2),
    and updates two output parameters with the number of num's proper divisors and their sum.

    For example, if this function is called with num = 12, since 1, 2, 3, 4 and 6 are 12's proper divisors,
    the function would update the output parameters with the numbers 5 and 16.

    Note: Pay attention to the running time of your function. An efficient implementation would run in Θ(√𝑛𝑢𝑚)

b. Use the function you wrote in section (a), to implement the function: bool isPerfect(int num)
    This function is given positive integer num (≥ 2), and determines if it is perfect number or not.

c. Use the functions you implemented in sections (a) and (b),
   to write a program that reads from the user a positive integer m (≥ 2), and prints:
    • All the perfect numbers between 2 and m.
    • All pairs of amicable numbers that are between 2 and m (both numbers must be in the range).

    Note: Pay attention to the running time of your implementation.
    An efficient algorithm for this part would call analyzeDividors Θ(m) times all together.

*/

#include <iostream>
#include <cmath>
using namespace std;

// Function Prototypes
void analyze_proper_divisors(int num, int& update_count_prop_divs, int& update_sum_prop_divs);
bool is_perfect(int num);

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
  cout << endl;  // Clean Formatting
  
  // Print all perfect numbers
  cout << "All the perfect numbers between 2 and " << num << ":" << endl;  
  for (int i = 2; i <= num; i++)
  {
    if (is_perfect(i))
    {
      cout << i << "\t";
    }
  }
  cout << endl;  // Clean Formatting
  cout << endl;  // Clean Formatting
  
  // Print all amicable numbers
  cout << "All the amicable numbers between 2 and " << num << ":" << endl;
  for (int x = 2; x <= num; x++)
  {
    // Local vars to be updated in place on each iteration
    int count_prop_divs_x = 0;  // Will not be used locally, but necessary for function call
    int sum_prop_divs_x = 0;
    int count_prop_divs_y = 0;  // Will not be used locally, but necessary for function call
    int sum_prop_divs_y = 0;
    
    analyze_proper_divisors(x, count_prop_divs_x, sum_prop_divs_x);
    int y = sum_prop_divs_x;

    analyze_proper_divisors(y, count_prop_divs_y, sum_prop_divs_y);
    
    if (y > x && x == sum_prop_divs_y)
    {
      cout << x << " and " << y << endl;
    }
  }
  
  return 0;
}

// This function receives a positive integer, and determines if it's a perfect number
bool is_perfect(int num)
{
  int count_prop_divs = 0;
  int sum_prop_divs = 0;

  analyze_proper_divisors(num, count_prop_divs, sum_prop_divs);
  
  if (num == sum_prop_divs)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// This function receives a positive integer, counts and sums its proper divisors
void analyze_proper_divisors(int num, int& update_count_prop_divs, int& update_sum_prop_divs)
{  
  for (int i = 1; i <= sqrt(num); i++)
  {
    if (num % i == 0)
    {
      update_count_prop_divs++;
      update_sum_prop_divs += i;
    }
  }
  for (int i = sqrt(num); i > 0; i--)
  {
    if ((i != 1) && (num % i == 0))  // Proper divisor does not include the num itself
    {
      if (num % i == 0)
      {
        if (i * i != num) // Account for duplicates
        {
          update_count_prop_divs++;
          update_sum_prop_divs += (num / i);
        }
      }
    }
  }
}