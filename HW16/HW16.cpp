/*

Assignment:
-----------

1. Implement a symbol balance checker function for the Pascal programming language.
    Pascal allows for the following pairs: {}, (), [], begin end.
    All programs will begin with the word "begin" and end  with the word "end".
    Your function should receive an ifstream object which is already open
    and will return true, all of the symbols match, or false, they do not. 
    You do not have to worry about comments in the program
    but you do have to avoid other parts of the program's code
    such as assignment statements (x = y) and other expressions.

2. Although a queue is "best" implemented with a list,
    it can be implemented with a vector if you take into account the starting position of the queue.
    For example, if five elements are pushed onto the queue,
    the start of the queue is at position zero and the end is at position 4.
    If we, then, pop two elements, the start would be at position 2 and the end at position 4.
    The two "popped" elements are not really removed from the vector,
    and that avoids the O(N) time problem for the pop function.
    
    Implement a class which uses a vector to store the queue.
    Be mindful of performance, such that if the queue is empty, the size of the underlying vector is "reset."

*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

/***************************************************/
/**********SECTION 2: QUEUE IMPLEMENTATION**********/
/***************************************************/
class Que
{
private:
    vector<int> v;
    int size = 0;
    int f_index = 0;    // Front
    int b_index = 0;    // Back
    int s_index = 0;    // Start

public:
    // Construct the queue
    Que() 
        : v(), 
        size(0),
        f_index(0),
        b_index(0),
        s_index(0) {}

    // Get size of queue
    int const& Size() const
    { return size; }

    // Get indices of queue
    int const& get_f_index() const
    { return f_index; }
    int const& get_b_index() const
    { return b_index; }
    int const& get_s_index() const
    { return s_index; }
    
    // Check if queue is empty
    bool IsEmpty()
    {
        if (size == 0)
        { return true; }
        else
        { return false; } 
    }
    
    // Reset queue: values will be overwritten
    void Reset()
    {
        f_index = 0;
        b_index = 0;
        s_index = 0;
    }
    
    // Insert element into back of queue
    void Push(int value)
    {
        if (IsEmpty())
        {
            v.push_back(value);
            ++size;
        }
        else
        {
            v.push_back(value);
            ++size;
            ++b_index;
        }
    }
    
    // Get last element in queue
    int back()
    { 
        if (!IsEmpty())
        {
            return v.back();
        }  
        else 
        { 
            cout << "No elements in queue!" << endl;
            Reset();
            cout << "Queue Emptied: ";
            return b_index;
        }
    }
    
    // Get first element in queue
    int front()
    {
        if (!IsEmpty())
        {
            return v.at(s_index);
        }
        else
        {
            cout << "No more elements in queue!" << endl;
            Reset();
            cout << "Queue Emptied: ";
            return f_index;
        }
    }

    // Remove first element from queue
    void pop()
    { 
        if (!IsEmpty())
        {
            ++f_index;
            s_index = f_index;
            size--;
        }
        else
        {
            cout << "No more elements in queue!" << endl;
            Reset();
        }
    }
};
void print_Q_status(Que& q);
void pop_elements_from_Q(Que& q, int num);
void push_elements_into_Q(Que& q, int num);



/***************************************************/
/**********SECTION 1: STACK IMPLEMENTATION**********/
/***************************************************/
const char L_BRACK = '[';
const char R_BRACK = ']';
const char L_PAREN = '(';
const char R_PAREN = ')';
const char L_CURLY = '{';
const char R_CURLY = '}';
bool match_syntax(ifstream& program_file);
void open_file(ifstream& input_file);



/************************/
/**********MAIN**********/
/************************/
int main()
{
    cout << endl;
    cout << "SECTION 2: QUEUE IMPLEMENTATION" << endl;
    cout << endl;
    Que q;
    push_elements_into_Q(q, 5);
    pop_elements_from_Q(q, 5);
    print_Q_status(q);
    cout << endl;

    cout << endl;
    cout << "SECTION 1: STACK IMPLEMENTATION" << endl;
    cout << endl;
    //Open Program File
    ifstream program_file;
    open_file(program_file);
    cout << "File opened successfully!" << endl;
    cout << endl;

    //Match Syntax
    if (match_syntax(program_file))
    { cout << "\nSYNTAX MATCHES!" << endl; }
    else
    { cout << "\nsyntax does NOT match :(" << endl; }

    program_file.close();
    
    return 0;
}

/**********SECTION 1: STACK IMPLEMENTATION**********/
bool match_syntax(ifstream& program_file)
{
    stack<char> c_stack;    // {}, [], ()
    stack<string> s_stack;  // BEGIN, END

    cout << "MATCHING IN PROGRESS.........." << endl;
    bool match = false;

    // Read file character by character
    char c = '\0';
    while (program_file >> c)
    {
        // If character is {}, (), [], push onto stack, otherwise read in next char
        if (c == L_BRACK || c == R_BRACK ||
            c == L_CURLY || c == R_CURLY ||
            c == L_PAREN || c == R_PAREN)
        {
            cout << "Read in char: " << c << endl;
            if (c_stack.empty())
            {
                cout << "Stack is Empty! Pushing char: " << c << " onto stack." << endl;
                c_stack.push(c);
            }
            else
            {
                cout << "Comparing " << c << " to first element on stack " << c_stack.top() << " ... ";
                if ((c == R_BRACK && c_stack.top() == L_BRACK) ||
                    (c == R_PAREN && c_stack.top() == L_PAREN) ||
                    (c == R_CURLY && c_stack.top() == L_CURLY))
                {
                    cout << "Popping char: " << c_stack.top() << " from stack." << endl;
                    c_stack.pop();
                }
                else
                {
                    cout << "Pushing char: " << c << " onto stack." << endl;
                    c_stack.push(c);
                }
            }
        }
    }
    program_file.clear();   // Clear state
    program_file.seekg(0);  // Seek back to beginning

    // Read file string by string
    string s = "";
    while (program_file >> s)
    {
        if (s == "BEGIN" || s == "begin")
        {
            cout << "Read in string: " << s << endl;
            cout << "Pushing string: " << s << " onto stack." << endl;
            s_stack.push(s);
            cout << "Top of stack: " << s_stack.top() << endl;
        }
        else if (s == "END" || s == "END." || s =="END;" || s == "end")
        {
            cout << "Comparing " << s << " to first element on stack " << s_stack.top() << " ... ";
            cout << "Popping char: " << s_stack.top() << " from stack." << endl;
            s_stack.pop();
        }
    }
    cout << "...............MATCHING FINISHED!" << endl;

    if (c_stack.empty() && s_stack.empty())
    { match = true; }
    else
    { match = false; }

    return match;
}

void open_file(ifstream& input_file)
{
    string users_file = "";
    cout << "Please enter the filename: ";
    cin >> users_file;
    input_file.open(users_file);
    while (!input_file)
    {
        cout << "Unable to open file." << endl;
        cout << "Please enter the filename: ";
        cin >> users_file;
        input_file.clear();
        input_file.open(users_file);
    }
}

/**********SECTION 2: QUEUE IMPLEMENTATION**********/
void print_Q_status(Que& q)
{
    cout << "------------------------" << endl;
    cout << "      QUEUE STATUS      " << endl;
    cout << "------------------------" << endl;
    
    if (q.IsEmpty())
    {
      cout << "QUEUE EMPTIED." << endl;
    }

    cout << endl;
}

void pop_elements_from_Q(Que& q, int num)
{
    int pop_count = 0;
    int num_of_elements_to_pop = num;
    
    cout << "-----------------------------------------" << endl;
    cout << "       POPPING ELEMENTS FROM QUEUE       " << endl;
    cout << "-----------------------------------------" << endl;
    
    for (int i = 1; i <= num_of_elements_to_pop; i++)
    {
      cout << "POPPING ELEMENT FROM QUEUE... " << ++pop_count << endl;
      cout <<"Previous Size: " << q.Size() << endl;
      cout << q.front() << " is " << "popped..." << endl;
      q.pop();
      cout <<"Updated Size: " << q.Size() << endl;
      cout << "Updated Front Element: " << q.front() 
        << " | Back Element: " << q.back() << endl;
      cout << "Front Index: " << q.get_f_index()
        << " | Back Index: " << q.get_b_index() << endl;
      cout << endl;
    }
    
    // // TEST: Pop Last Element
    // cout << "POPPING ELEMENT FROM QUEUE... " << ++pop_count << endl;
    // cout <<"Previous Size: " << q.Size() << endl;
    // cout << q.front() << " is " << "popped..." << endl;
    // q.pop();
    // cout <<"Updated Size: " << q.Size() << endl;
    // cout << "Updated Front Element: " << q.front() 
    //   << " | Back Element: " << q.back() << endl;
    // cout << "Front Index: " << q.get_f_index()
    //   << " | Back Index: " << q.get_b_index() << endl;
    // cout << endl;
}

void push_elements_into_Q(Que& q, int num)
{
    int push_count = 0;
    int num_of_elements_to_push = num;

    cout << "-----------------------------------------" << endl;
    cout << "       PUSHING ELEMENTS INTO QUEUE       " << endl;
    cout << "-----------------------------------------" << endl;
    
    for (int i = 1; i <= num_of_elements_to_push; i++)
    {
      cout << "PUSHING ELEMENT INTO QUEUE... " << ++push_count << endl;
      cout <<"Previous Size: " << q.Size() << endl;
      q.Push(i*10);
      cout <<"Updated Size: " << q.Size() << endl;
      cout << "Front Element: " << q.front() 
        << " | Back Element: " << q.back() << endl;
      cout << "Front Index: " << q.get_f_index()
        << " | Back Index: " << q.get_b_index() << endl;
      cout << endl;
    }
}