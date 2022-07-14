/* 

Assignment:
-----------

Write a program that reads a person’s name in the following format:
first name, then middle name or initial, and then last name.

The program then outputs the name in the following format:
Last_Name, First_Name Middle_Initial.

For example, the input Mary Average User
should produce the output: User, Mary A.

The input Mary A.User should also produce the output: User, Mary A.

Note that your program should work the same
and place a period after the middle initial
even if the input did not contain a period.

Hint: You may want to use three string variables
rather than one large string variable for the input.
You may find it easier to not use getline.

*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
  string f_name = "";
  string m_name = "";
  string m_initial = "";
  string l_name = "";

  // Prompt User
  cout << "Please enter your name in the following format:" << endl;
  cout << "(First Name, Middle Name, Last Name)" << endl;
  cin >> f_name;
  cin >> m_name;
  cin >> l_name;

  // Set middle intitial
  m_initial = m_name[0];

  // Print format to Last Name, First Name, Middle Initial
  cout << l_name + ", " + f_name + " " + m_initial + ". " << endl;

  return 0;
}