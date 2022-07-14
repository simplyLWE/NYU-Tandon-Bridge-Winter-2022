/*

Assignment:
-----------

a. Implement a function:
    int printMonthCalender(int numOfDays, int startingDay)
    
    This function is given two parameters:
    • numOfDays - The number of days in the month
    • startingDay – a number 1-7 that represents the day in the week of the first day in that month (1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.).

    The function should:
    • Print a formatted monthly calendar of that month
    • Return a number 1-7 that represents the day in the week of the last day in that month.

    Formatting Notes:
    • The output should include a header line with the days’ names.
    • Columns should be spaced by a tab.

    Example: when calling printMonthCalender(31, 4) it should return 6, and should print:

    Mon Tue Wed Thr Fri Sat Sun
                1   2   3   4
    5   6   7   8   9   10  11
    12  13  14  15  16  17  18
    19  20  21  22  23  24  25
    26  27  28  29  30  31

b. A method for determining if a year is a leap year in the Gregorian calendar system is to check if it is divisible by 4 but not by 100, unless it is also divisible by 400.
    For example, 1896, 1904, and 2000 were leap years but 1900 was not.

    Write a function that takes in a year as input and returns true if the year is a leap year, returns false otherwise.
    
    Note: background on leap year https://en.wikipedia.org/wiki/Leap_year

c. Implement a function:
    void printYearCalender(int year, int startingDay)

    This function is given two parameters:
    • year – an integer that represents a year (e.g. 2016)
    • startingDay – a number 1-7 that represents the day in the week of 1/1 in that year (1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.).

    The function should use the functions from sections (a) and (b) in order to print a formatted yearly calendar of that year.

    Formatting Note: As the header for each month you should print the month's name followed by the year (e.g. March 2016).
    Example: Appendix A shows the expected output of the call printYearCalender(2016, 5).

d. Write program that interacts with the user and your function in (c).

*/

#include <iostream>
using namespace std;

int const JAN = 1;
int const FEB = 2;
int const MAR = 3;
int const APR = 4;
int const MAY = 5;
int const JUN = 6;
int const JUL = 7;
int const AUG = 8;
int const SEP = 9;
int const OCT = 10;
int const NOV = 11;
int const DEC = 12;

int const MONTH_HAS_28_DAYS = 28;  // February Common Year
int const MONTH_HAS_29_DAYS = 29;  // February Leap Year
int const MONTH_HAS_30_DAYS = 30;
int const MONTH_HAS_31_DAYS = 31;

// Gregorian calendar didn't replace the Julian calendar until 1752
int const GREG_CAL_BEGINS = 1752;

// Function Prototypes
int print_month_calendar(int starting_day, int number_of_days);
void print_year_calendar(int year, int starting_day);
bool is_leap_year(int year);

int main()
{
  int year = 0;
  int starting_day = 0;

  //Prompt user
  do
  {
    cout << "Please enter the year: ";
    cin >> year;
    cout << "Please enter the starting day (i.e. 1=MON, 2=TUE, 3=WED, ...): ";
    cin >> starting_day;
  }
  while (year < GREG_CAL_BEGINS || (starting_day < 1 || starting_day > 7));
  
  cout << endl;  // Formatting
  
  print_year_calendar(year, starting_day);

  return 0;
}

  /*-----------------------------------------------------------/
 / Print Year Calendar Function                               /
/-----------------------------------------------------------*/ 
void print_year_calendar(int year, int starting_day)
{
  // Determine Leap Year
  bool leap_year = is_leap_year(year);
  
  // Print Each Month Calendar
  int subsequent_day = 0;
  for (int month = JAN; month <= DEC; month++)
  {
    //---JANUARY---//
    if (month == JAN)
    {
      cout << "January " << year << endl;
      subsequent_day = print_month_calendar(starting_day, MONTH_HAS_31_DAYS);
    }
    //-----FEBRUARY-----//
    else if (month == FEB)
    {
      cout << "February " << year << endl;
      if (leap_year == true)  // February Leap Year
      {
        subsequent_day = print_month_calendar(subsequent_day, MONTH_HAS_29_DAYS);
      }
      else if (leap_year == false)  // February Common Year
      {
        subsequent_day = print_month_calendar(subsequent_day, MONTH_HAS_28_DAYS);
      }
    }
    //-------MARCH-------//
    else if (month == MAR)
    {
      cout << "March " << year << endl;
      subsequent_day = print_month_calendar(subsequent_day, MONTH_HAS_31_DAYS);
    }
    //------APRIL------//
    else if (month == APR)
    {
      cout << "April " << year << endl;
      subsequent_day = print_month_calendar(subsequent_day, MONTH_HAS_30_DAYS);
    }
    //-------MAY-------//
    else if (month == MAY)
    {
      cout << "May " << year << endl;
      subsequent_day = print_month_calendar(subsequent_day, MONTH_HAS_31_DAYS);
    }
    //-------JUNE-------//
    else if (month == JUN)
    {
      cout << "June " << year << endl;
      subsequent_day = print_month_calendar(subsequent_day, MONTH_HAS_30_DAYS);
    }
    //-----JULY-----//
    else if (month == JUL)
    {
      cout << "July " << year << endl;
      subsequent_day = print_month_calendar(subsequent_day, MONTH_HAS_31_DAYS);
    }
    //----AUGUST----//
    else if (month == AUG)
    {
      cout << "August " << year << endl;
      subsequent_day = print_month_calendar(subsequent_day, MONTH_HAS_31_DAYS);
    }
    //---SEPTEMBER---//
    else if (month == SEP)
    {
      cout << "September " << year << endl;
      subsequent_day = print_month_calendar(subsequent_day, MONTH_HAS_30_DAYS);
    }
    //---OCTOBER---//
    else if (month == OCT)
    {
      cout << "October " << year << endl;
      subsequent_day = print_month_calendar(subsequent_day, MONTH_HAS_31_DAYS);
    }
    //---NOVEMBER---//
    else if (month == NOV)
    {
      cout << "November " << year << endl;
      subsequent_day = print_month_calendar(subsequent_day, MONTH_HAS_30_DAYS);
    }
    //---DECEMBER---//
    else if (month == DEC)
    {
      cout << "December " << year << endl;
      subsequent_day = print_month_calendar(subsequent_day, MONTH_HAS_31_DAYS);
    }
  }
}

  /*-----------------------------------------------------------/
 / Print Month Calendar Function                              /
/-----------------------------------------------------------*/ 
int print_month_calendar(int starting_day, int number_of_days)
{
  int const DAYS_IN_WEEKS = 7;
  int day_index = starting_day - 1; // Zero-index days from 1 to 0
  
  // Print Weekday Header
  cout << "Mon\t" << "Tue\t" << "Wed\t" << "Thu\t"
  << "Fri\t" << "Sat\t" << "Sun\t" << endl;
  
  // Print Tacs
  for (int s = 1; s < starting_day; s++)
  {
    cout << "-\t";
  }
  
  // Print Days
  for (int day = 1; day <= number_of_days; day++)
  {
    cout << day << "\t";
    if ((day + day_index) % DAYS_IN_WEEKS == 0)
    {
      cout << endl;
    }
    // Format Last Week
    if (day == number_of_days)
    {
      cout << endl;
    }
  }
  cout << endl;

  // Determine Last Day of Month
  int last_day = 0;
  
  if (number_of_days == MONTH_HAS_31_DAYS)
  {
    last_day = (starting_day + 2) % DAYS_IN_WEEKS;
  }
  else if (number_of_days == MONTH_HAS_30_DAYS)
  {
    last_day = (starting_day + 1) % DAYS_IN_WEEKS;
  }
  else if (number_of_days == MONTH_HAS_28_DAYS)  // Common Year
  {
    last_day = (starting_day - 1) % DAYS_IN_WEEKS;
  }
  else if (number_of_days == MONTH_HAS_29_DAYS)  // Leap Year
  {
    last_day = starting_day;
  }
  
  // Reset Day 0 to 7
  if (last_day == 0)
  {
    last_day = 7;
  }
  
  // Return Starting Day of Next Month
  int subsequent_day = (last_day + 1) % DAYS_IN_WEEKS;
  // Reset Day 0 to 7
  if (subsequent_day == 0)
  {
    subsequent_day = 7;
  }
  return subsequent_day;
}

  /*-----------------------------------------------------------/
 / Leap Year Determination Function                           /
/-----------------------------------------------------------*/ 
bool is_leap_year(int year)
{
    if (year % 4 == 0 && year % 400 == 0 && year % 100 == 0)
    {
        return true;
    }
    else if (year % 4 == 0 && year % 100 != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}