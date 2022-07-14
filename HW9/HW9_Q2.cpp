/*

Assignment:
-----------

Two strings are anagrams if the letters can be rearranged to form each other.
For example, “Eleven plus two” is an anagram of “Twelve plus one”.
Each string contains one ‘v’, three ‘e’s, two ‘l’s, etc.

Write a program that determines if two strings are anagrams.
The program should not be case sensitive and should disregard any punctuation or spaces.

1. Think how to break down your implementation to functions.
2. Pay attention to the running time of your program. If each input string contains n characters,
   an efficient implementation would run in a linear time (that is Θ(n)).

*/

#include <iostream>
#include <string>
using namespace std;

void to_lower(string &word);
void count_letters(string str, int arr[], int arr_size);
void print_array(int arr[], int arr_size);
void print_map(int arr[], int arr_size);

const int ALPHABET_SIZE = 26;

/*
TO-DO
[x] Get words from user
[x] Convert to single case
  [x] Write to_lower function
[x] Count letters in each word
  [x] Write count_letters function
[ ] Compare letters in array of word1 to letters in array of word2
[ ] Write is_anagram function
*/

int main()
{
  // Get 2 words from user
  string word1 = "";
  string word2 = "";
  cout << "Please enter the first string: ";
  getline(cin, word1);
  cout << "Please enter the second string: ";
  getline(cin, word2);

  // Preserve original words
  string orig_word1 = word1;
  string orig_word2 = word2;

  //Convert chars to lowercase
  to_lower(word1);
  to_lower(word2);
  cout << endl;

  // Count number of letters in string
  int word1_count[26] = {0};  // Init to 0 to prevent garbage values
  int word1_count_size = ALPHABET_SIZE;

  int word2_count[26] = {0};  // Init to 0 to prevent garbage values
  int word2_count_size = ALPHABET_SIZE;

  // Word 1 Array
  count_letters(word1, word1_count, word1_count_size);
  print_map(word1_count, word1_count_size);
  cout << endl;
  // Word 2 Array
  count_letters(word2, word2_count, word2_count_size);
  print_map(word2_count, word2_count_size);
  cout << endl;

  // We know for certain if the string lengths are different,
  // then they're obviously not anagrams
  // However we still need to compare actual values,
  // i.e. hello and jello have same length but are not anagrams
  if (word1.length() != word2.length())
  {
    cout << orig_word1 << " and " << orig_word2
      << " are NOT anagrams" << endl;
  }

  // Compare values in each array
    // If all values match, set bool to true and return is_anagram
    // Else, set bool to false and return !is_anagram

  bool is_anagram;
  for (int i = 0; i < ALPHABET_SIZE; i++)
  {
    if (word1_count[i] == word2_count[i])
    {
      is_anagram = true;
      continue;
    }
    else
    {
      is_anagram = false;
      break;
    }
  }

  if (is_anagram)
  {
    cout << "Strings are anagrams!" << endl;
  }
  else
  {
    cout << "Strings are NOT anagrams!" << endl;
  }
    
  return 0;
}


void print_map(int arr[], int arr_size)
{
  // Alphabet Mapping
  for (int i = 0; i < arr_size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  for (char c = 'a'; c <= 'z'; c++)
  {
    cout << c << " ";
  }
  cout << endl;
}

void print_array(int arr[], int arr_size)
{
  for (int i = 0; i < arr_size; i++)
  {
    if (arr[i] > 0)
    {
      cout << (char) (i + 'a') << "\t";
    }
  }
  cout << endl;
  for (int i = 0; i < arr_size; i++)
  {
    if (arr[i] > 0)
    {
      cout << arr[i] << "\t";
    }
  }
  cout << endl;
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

void to_lower(string &word)
{
  int offset = 32; // Uppercase-to-lowercase offset in ASCII
  for (int c = 0; c < word.length(); c++)
  {
    if (word[c] >= 'A' && word[c] <= 'Z')
    {
      word[c] = word[c] + offset;
    }
  }
}