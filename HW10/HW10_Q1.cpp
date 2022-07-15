/*

Assignment:
-----------

Implement the function:
string* createWordsArray(string sentence, int& outWordsArrSize)

This function gets a string sentence containing a sentence.
When called, it should create and return a new array (of strings), that contains all the words in sentence.
The function should also update the output parameter, outWordsArrSize, with the logical size of the new array that was created.

Note: Assume that the words in the sentence are separated by a single space.

For example, if sentence = ”You can do it”, after calling createWordsArray(sentence, outWordsArrSize),
the function should create and return an array that contains [”You” , ”can” , ”do” , ”it”],
and update the value in outWordsArrSize to be 4.

Implementation requirements:
1. You may want to use some of the string methods, such as find, substr, etc.
2. Your function should run in linear time. That is, if sentence contains n characters, your function should run in 𝜃(n).
3. Write a main() program that tests this function.

*/

#include <iostream>
#include <string>
using namespace std;

void print_array(string arr[], int size);
int count_words(string sentence);
string* create_words_array(string sentence, int& arr_size);

int main()
{
  // Prompt user for sentence
  string sentence = "";
  do
  {
    cout << "Please enter a sentence: " << endl;
    getline(cin, sentence);
  }
  while (sentence.empty());

  cout << "Sentence: " << sentence << endl;
  int len = sentence.length();
  cout << "Length of sentence: " << len << endl;
  int num_of_words = count_words(sentence);
  cout << "Number of words in sentence: " << num_of_words << endl;
  cout << endl;

  //Take this sentence & create an array of words
  //This will eventually point to the words array on the heap 
  string* words_arr = NULL;
  int words_arr_size = 0;

  words_arr = create_words_array(sentence, words_arr_size);
  print_array(words_arr, words_arr_size);

  // Free up memory allocation
  delete [] words_arr;
  words_arr = NULL;

  return 0;
}

// Creates a new array on the heap and returns a pointer to that array
// Updates the size of the new array as a pass-by-reference
string* create_words_array(string sentence, int& arr_size)
{
  // Get num of words from sentence to update array size in place
  arr_size = count_words(sentence);

  // Create ptr to new array of words on heap
  string* words_arr = new string[arr_size];
  
  // Populate array with words from sentence
  // Feed chars one by one into array until a space is encountered
  // Skip space and increment array index to create new word
  int len = sentence.length();
  int arr_index = 0;
  for (int c = 0; c < len; c++)
  {
    if (sentence[c] == ' ')
    {
      c++;  // Skip space
      arr_index++;  // Create new index for new word in array
    }
    words_arr[arr_index] = words_arr[arr_index] + sentence[c];
  }
  return words_arr;
}

int count_words(string sentence)
{
  int len = sentence.length();
  
  int word_count = 0; 
  for (int i = 0; i <= len; i++)
  {
    if (sentence[i] == ' ' || i == len)
    {
      word_count++;
    }
  }
  return word_count;
}

void print_array(string arr[], int size)
{
  cout << "Array of words:" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << "Word: " << arr[i];
    cout << " || Index: " << i << endl;
  }
}