/* 

Assignment:
-----------

Traditional password entry schemes are susceptible to "shoulder surfing" in which an attacker
watches an unsuspecting user enter their password or PIN number and uses it later to gain
access to the account. One way to combat this problem is with a randomized challenge-
response system. In these systems the user enters different information every time, based on a
secret in response to a randomly generated challenge.

Consider the following scheme, in which the password consists of a five-digit PIN number (00000
to 99999). Each digit is assigned a random number that is 1, 2, or 3. The user enters the random
numbers that correspond to their PIN instead of their actual PIN numbers.

For example, consider an actual PIN number of 12345.
To authenticate the user would be presented with a screen such as:
PIN: 0123456789
NUM: 3231132213

The user would enter 23113 instead of 12345. This doesn’t divulge the password even if an
attacker intercepts the entry because 23113 could correspond to other PIN numbers, such as
69440 or 70439.

The next time the user logs in, a different sequence of random numbers would be generated, such as:
PIN: 0123456789
NUM: 1123122333

Write a program to simulate the authentication process. Store an actual 5-digit PIN number in
your program (make one up, and store it as a constant). The program should use an array to
assign random numbers to the digits from 0 to 9. Output the random digits to the screen, input
the response from the user, and output whether or not the user’s response correctly matches
the PIN number.

Assuming that the actual PIN number is 12345, your program should interact with the user
exactly as it shows in the following examples (2 different executions of the program):

Please enter your PIN according to the following mapping:
PIN: 0123456789
NUM: 3231132213
23113
Your PIN is correct

Please enter your PIN according to the following mapping:
PIN: 0123456789
NUM: 1123122333
23113
Your PIN is not correct

Note: Think how to break down your implementation to functions.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Function Prototypes
void print_array(int arr[], int arr_size);
void init_rand_num_array(int arr[], int arr_size);
void print_match(bool val);

// User's PIN
const int PIN[5] = {1,2,3,4,5};

int main()
{
  cout << "Please enter PIN according to the following mapping: "
  << endl;

  // Init and print PIN array
  int pin_arr_size = 10;
  int pin_arr[10] = {0,1,2,3,4,5,6,7,8,9};
  cout << "PIN: ";
  print_array(pin_arr, pin_arr_size);
  
  // Init and print array of randomly generated numbers
  int rand_num_arr_size = 10;
  int rand_num_arr[10];
  init_rand_num_array(rand_num_arr, rand_num_arr_size);
  cout << "NUM: ";
  print_array(rand_num_arr, rand_num_arr_size);

  // Prompt User
  string user_pin = "";
  cin >> user_pin;
  int pin_length = user_pin.length();  // Set length of string
  
  //Iterate over user pin and compare to mapping
  bool is_pin_match = true;
  for (int i = 0; i < pin_length; i++)
  {
    int key = PIN[i]; // Key for random number array
    if ((user_pin[i] - '0') != rand_num_arr[key])
    {
      is_pin_match = false;
    }
  }
  // Print results
  print_match(is_pin_match);

  return 0;
}

void init_rand_num_array(int arr[], int arr_size)
{
  srand(time(0));  // Init seed for rand num generator
  int rand_num = 0;  
  for (int i = 0; i < arr_size; i++)
  {
    rand_num = rand() % 3 + 1; // Modify range: {1,2,3}
    arr[i] = rand_num; // Store random number in array
  }
}

void print_array(int arr[], int arr_size)
{
  for (int i = 0; i < arr_size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void print_match(bool val)
{
  if (val)
  {
    cout << "The PIN is correct." << endl;
  }
  else
  {
    cout << "The PIN is NOT correct." << endl;
  }
}