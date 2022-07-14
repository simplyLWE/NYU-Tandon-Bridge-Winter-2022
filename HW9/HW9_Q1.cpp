/*

Assignment:
-----------

Write a program that will read in a line of text and output the number of words in the line
and the number of occurrences of each letter.

Define a word to be any string of letters that is delimited at each end by either
whitespace, a period, a comma, or the beginning or end of the line.

You can assume that the input consists entirely of letters, whitespace, commas, and periods.

When outputting the number of letters that occur in a line,
be sure to count upper and lowercase versions of a letter as the same letter.

Output the letters in alphabetical order and list only those letters that do occur in the input line.

Your program should interact with the user exactly as it shows in the following example:

Please enter a line of text: I say Hi.
3 words
1 a
1 h
2 i
1 s
1 y

Notes:
1. Think how to break down your implementation to functions.
2. Pay attention to the running time of your program.
   If the input line contains n characters, an efficient implementation would run in a linear time (that is Θ(n)).

*/

#include <iostream>
#include <string>
using namespace std;

int count_words(string str);
void count_letters(string str, int arr[], int arr_size);
void print_letters_map(int arr[], int arr_size);

const int ALPHABET_SIZE = 26;

int main()
{
  // Get string from user
  string user_string = "";
  cout << "Please enter a line of text: " << endl;
  getline(cin, user_string);

  // Count number of words in string
  int num_of_words = count_words(user_string);
  cout << "Total number of words: " << num_of_words << endl;
  
  // Count number of letters in string
  int count_letters_arr[26] = {0};  // Init to 0 to prevent garbage values
  int count_letter_arr_size = ALPHABET_SIZE;
  
  count_letters(user_string, count_letters_arr, count_letter_arr_size);
  print_letters_map(count_letters_arr, count_letter_arr_size);

  return 0;
}

int count_words(string str)
{
  int word_count = 0;
  
  // Loop over every char in string to count words
  int len = str.length();
  for (int i = 0; i < len; i++)
  {
    // Check upper- and lowercase letters and subsequent punctuation 
    if ( 
      ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
      && (str[i + 1] == ' ' || str[i + 1] == ',' || str[i + 1] == '.'))
      {
        word_count++;
      }
  }
  return word_count;
}

void count_letters(string str, int arr[], int arr_size)
{
  int len = str.length();
  for (int i = 0; i < len; i++)
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
    {
      arr[str[i] - 'A']++;
    }
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      arr[str[i] - 'a']++;
    }
  }
}

void print_letters_map(int arr[], int arr_size)
{
  for (int i = 0; i < arr_size; i++)
  {
    if (arr[i] > 0)
    {
      cout << arr[i] << "\t" << (char) (i + 'a') << endl;
    }
  }
}