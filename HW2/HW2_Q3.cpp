/*

Assignment:
-----------

Suppose John and Bill worked for some time and we want to calculate the total time both of them worked.
Write a program that reads number of days, hours, minutes each of them worked, 
and prints the total time both of them worked together as days, hours, minutes.

Hint: Try to adapt the elementary method for addition of numbers to this use.

Your program should interact with the user exactly as it shows in the following example:

Please enter the number of days John has worked: 2
Please enter the number of hours John has worked: 12
Please enter the number of minutes John has worked: 15

Please enter the number of days Bill has worked: 3
Please enter the number of hours Bill has worked: 15
Please enter the number of minutes Bill has worked: 20

The total time both of them worked together is: 6 days, 3 hours and 35 minutes.

*/

#include <iostream>
using namespace std;

int main()
{
  // Vars for John
  int j_days = 0;
  int j_hours = 0;
  int j_minutes = 0;

  // Get time John worked
  cout << "Please enter the number of days John worked: ";
  cin >> j_days;
  cout << "Please enter the number of hours John worked: ";
  cin >> j_hours;
  cout << "Please enter the number of minutes John worked: ";
  cin >> j_minutes;

  // Formatting
  cout << endl;

  // Vars for Bill
  int b_days = 0;
  int b_hours = 0;
  int b_minutes = 0;

  // Get time Bill worked
  cout << "Please enter the number of days Bill worked: ";
  cin >> b_days;
  cout << "Please enter the number of hours Bill worked: ";
  cin >> b_hours;
  cout << "Please enter the number of minutes Bill worked: ";
  cin >> b_minutes;

  // Formatting
  cout << endl;

  // Combine time worked
  int days = j_days + b_days;
  int hours = j_hours + b_hours;
  int mins = j_minutes + b_minutes;

  // Calculate total time worked
  int total_days = days + (hours/24);
  int total_hours = (hours % 24) + (mins / 60);
  int total_mins = (mins % 60);

  // Print results
  cout << "The total time both of them worked together is: "
  << total_days << " days, "
  << total_hours << " hours, "
  << total_mins << " minutes." << endl;

  return 0;
} 