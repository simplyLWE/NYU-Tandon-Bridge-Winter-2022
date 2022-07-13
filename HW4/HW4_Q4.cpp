/*

Assignment:
-----------

Write two versions of a program that reads a sequence of positive integers from the user,
calculates their geometric mean, and prints the geometric mean.

Notes:
1. In mathematics, geometric mean of a dataset {a1, a2, a3, ... , an} containing positive numbers,
  is given by: (a1 ∙ a2 ∙ a3 ∙ ... ∙ an) ^ (1/n).

  For example, the geometric mean of 2, 9 and 12 is equal to 6: (2 ∙ 9 ∙ 12) ^ (1/3) = 6.

2. In order to calculate the n-th root of a number, you should call the pow function, located in the cmath library.

Your two versions should read the integer sequence in two ways:

a) First read the length of the sequence.
    
    For example, an execution would look like:
  
    Please enter the length of the sequence: 3
    Please enter your sequence:
    1
    2
    3
    The geometric mean is: 1.8171

b) Keep reading the numbers until -1 is entered.
    
    For example, an execution would look like:
    
    Please enter a non-empty sequence of positive integers, each one in a separate line.
    End your sequence by typing -1:
    1
    2
    3
    -1
    The geometric mean is: 1.8171

*/

#include <iostream>
#include <cmath>
using namespace std;

// Constant for section (b) implementation
const int END_SEQUENCE = -1;

int main()
{
  /*--------------------------------------/
  Section (a) implementation:
  "First read the length of the sequence."
  /--------------------------------------*/
  cout << "Section (a):" << endl;

  double num = 0;
  double len = 0; // Determines exponent
  double mult_nums = 0; // Determines base

  // Prompt user for length of sequence
  do
  {
    cout << "Please enter the length of the sequence: ";
    cin >> len;
  }
  while (len <= 0);

  // Collect positive integers from user
  cout << "Please enter the sequence:" << endl;
  for (int n = 1; n <= len; n++)
  {
    cin >> num;

    if (mult_nums == 0) // Add first num
    {
      mult_nums = num + mult_nums;
    }
    else  // Then continue to multiply
    {
      mult_nums = num * mult_nums;
    }
  }

  // Calculate geometric mean
  double for_base = mult_nums;
  double for_exponent = 1 / len;  // Convert to exponential value
  double for_geo_mean = pow(for_base, for_exponent);

  cout << "The geometric mean is: " << for_geo_mean << endl;

  // Formatting
  cout << endl;

  /*---------------------------------------------/
  Section (b) implementation:
  "Keep reading the numbers until -1 is entered."
  /---------------------------------------------*/

  cout << "Section (b):" << endl;

  double curr_num = 0;
  double count_nums = 0;  // Determines exponent
  double nums_product = 0;  // Determines base
  
  cout << "Please enter a non-empty sequence of positive integers, "
  << "each one in a separate line. End the sequence by typing -1: " << endl;

  // Collect positive integers from user
  bool end_input = false;
  while (end_input == false)
  {
    cin >> curr_num;
    // Consider the case there is no sequence    
    if (curr_num == END_SEQUENCE)
    {
      end_input = true;
    }
    // Otherwise continue reading in numbers
    else
    {
      count_nums++; // Count all nums
      if (nums_product == 0)  // Add first num
      {
        nums_product = curr_num + nums_product;
      }
      else  // Then continue to multiply
      {
        nums_product = curr_num * nums_product;
      }
    }    
  }

  // Calculate geometric mean
  double base = nums_product;
  double exponent = 1 / count_nums; // Convert to exponential value
  double geo_mean = pow(base, exponent);

  cout << "The geometric mean is: " << geo_mean << endl;

  return 0;
}