/*

Assignment:
-----------

Write a program that computes the cost of a long-distance call. The cost of the call is determined according to the following rate schedule:
• Any call started between 8:00 A.M. and 6:00 P.M., Monday through Friday, is billed at a rate of $0.40 per minute.
• Any call starting before 8:00 A.M. or after 6:00 P.M., Monday through Friday, is charged at a rate of $0.25 per minute.
• Any call started on a Saturday or Sunday is charged at a rate of $0.15 per minute.

The input will consist of the day of the week, the time the call started, and the length of the call in minutes.
The output will be the cost of the call.

Notes:
1. The time is to be input in 24-hour notation, so the time 1:30 P.M. is input as 13:30
2. The day of the week will be read as one of the following two character string: Mo Tu We Th Fr Sa Su
3. The number of minutes will be input as a positive integer.

*/

#include <iostream>
#include <string>
using namespace std;

// Constants for call rate schedule
const double MON_FRI_8_TO_6 = 0.40;
const double BEFORE_8_AFTER_6_MON_FRI = 0.25;
const double SAT_SUN = 0.15;

int main()
{
  // Vars for user input
  string day = "";
  int time_hours = 0;
  int time_minutes = 0;
  char time_colon = '\0';
  int call_length = 0;

  // Prompt user for call information
  cout << "Please enter the day of the week "
  << "(i.e. Mo Tu We Th Fr Sa Su): ";
  cin >> day;

  cout << "Please enter the time the call started "
  << "(i.e. 1:30 P.M. as 13:30): ";
  cin >> time_hours >> time_colon >> time_minutes;

  cout << "Please enter the length of the call in minutes: ";
  cin >> call_length;

  // Formatting
  cout << endl;

  // Var for calculating call price
  double call_price = 0;

  // Calculate call price on weekdays
  if (day == "Mo" || day == "Tu" || day == "We" || day == "Th" || day == "Fr")
  {
    // Calculate call price between 8am and 6pm
    if (time_hours >= 8 && time_hours <= 18)
    {
      call_price = call_length * MON_FRI_8_TO_6;
    }
    // Calculate call price of remaining time in week days
    // Between 12:01am and 7:59am and between 6pm and 12:59pm
    if (time_hours > 0 && time_hours < 8 || time_hours > 18 && time_hours <= 23)
    {
      call_price = call_length * BEFORE_8_AFTER_6_MON_FRI;
    }
  }
  // Calculate call price on weekends between 12:01am and 11:59pm
  if (day == "Sa" || day == "Su")
  {
    if (time_hours >= 0 && time_hours <= 23)
    {
      call_price = call_price = call_length * SAT_SUN;
    }
  }
  cout << "Cost of call is $" << call_price << endl;

  // Need to implemement cases when calls roll over from one pay rate into another pay rate,
  // i.e. a Friday night call before midnight that rolls into Saturday after midnight, or a weekday morning call before 8am that rolls past 8am, etc.

  return 0;
}