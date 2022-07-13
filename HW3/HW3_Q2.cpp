/*

Assignment:
-----------

Write a program that:
• Asks the user for their name.
• Asks the user to input their graduation year.
• Asks the user to input the current year.

Assume the student is in a four-year undergraduate program. Display the current status the student is in.
Possible status include: not in college yet, freshman, sophomore, junior, senior, graduated.

Note: If graduation year equals to current year, status is ‘Graduated’; if graduation year is four years after current year, status is ‘Freshman’, etc.

Your program should interact with the user exactly as it shows in the following example:

Please enter your name: Jessica
Please enter your graduation year: 2019
Please enter current year: 2015
Jessica, you are a Freshman

*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
  // Vars for user input
  string name = "";
  int grad_year = 0;
  int current_year = 0;
  
  // Prompt user for information
  cout << "Please enter your name: ";
  cin >> name;

  cout << "Please enter your graduation year: ";
  cin >> grad_year;
  if (grad_year <= 0)
  {
    cout << "Please enter a valid graduation year: ";
    cin >> grad_year;
  }

  cout << "Please enter the current year: ";
  cin >> current_year;
  if (current_year <= 0)
  {
    cout << "Please enter a valid current year: ";
    cin >> current_year;
  }

  // Determine student status
  int status = grad_year - current_year;

  if (status < 1)
  {
    cout << name << ", you graduated." << endl;
  }
  if (status == 1)
  {
    cout << name << ", you are a Senior." << endl;
  }
  if (status == 2)
  {
    cout << name << ", you are a Junior." << endl;
  }
  if (status == 3)
  {
    cout << name << ", you are a Sophomore." << endl;
  }
  if (status == 4)
  {
    cout << name << ", you are a Freshman." << endl;
  }
  if (status > 4)
  {
    cout << name << ", you are not in college yet." << endl;
  }

  return 0;
}