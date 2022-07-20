/*

Assignment:
-----------

Design a system to keep track of employee data.
The system should keep track of an employee’s name, ID number and hourly pay rate in a class called Employee.
You may also store any additional data you may need, hint, you need something extra.
This data is stored in a file (user selectable) with the id number, hourly pay rate, and the employee’s full name (example):

17 5.25 Daniel Katz
18 6.75 John F. Jones

Additionally we would like to be able to print payroll information from data in a different file.
The data is the employee’s id number and a number of hours that they worked (example):

17 40
18 20
18 20

As you see we can have the same number listed twice in which case that person should be paid the sum of the numbers
(John Jones did 40 hours work, but it’s listed as 20 + 20).

You should start by reading in the first file and storing the data as objects in a linked list.
You will need to create the linked list class and the Employee data class.
You may choose to use the Linked List class we created, or you may opt to create your own doubly linked list class.
(Note: if you cannot get either working, you can use the STL list class but 20% will be deducted).
The Linked list could be templated or not, it’s up to you,
however templating it would allow it to be used for other projects, so it might be a good idea.

Once you have read in the information from the first file, read in the second file.
Ultimately we would like to print payroll information based on the hourly wage from the first file
multiplied by the number of times an employee worked in the second file.
How you do this is entirely up to you.

The output must be in sorted (descending; so the person who gets paid most prints first) order in the form of:

*********Payroll Information******
Daniel Katz, $270
John F. Jones, $210
*********End Payroll**************

*/

#include <iostream>
#include <fstream>
using namespace std;

// This is the "Employee" class, per the assignment, named differently
class LinkedListNode
{
public:
    int ID;
    double Payrate;
    string Name;
    int Hours = 0;
    double Paycheck = 0.00;
    
    LinkedListNode* Previous;
    LinkedListNode* Next;

    LinkedListNode(int id, double payrate, string name,
                    LinkedListNode* previous = nullptr,
                    LinkedListNode* next = nullptr)
        : ID(id), Payrate(payrate), Name(name), Previous(previous), Next(next) {}

    void CalculateTotalHoursWorked(int hours)
    {
        Hours += hours;
    }

    void CalculatePayCheck()
    {
        Paycheck = Hours * Payrate;
    }
};

class LinkedList
{
private:
    LinkedListNode* Head;

public:
    LinkedList() : Head(nullptr) {}

    void PushBack(int id, double payrate, string name)
    {
        // Empty Case
        if (Head == nullptr)
        {
            Head = new LinkedListNode(id, payrate, name);
        }

        // Non-Empty Case
        else
        {
            LinkedListNode* Current = Head;
            while (Current->Next != nullptr)
            {
                Current = Current->Next;
            }
            LinkedListNode* Temp = new LinkedListNode(id, payrate, name, Current);
            Current->Next = Temp;
        }
    }

    // Get First Element of List
    LinkedListNode* GetHead()
    {
        if (Head == nullptr)
        {
            cout << "List is Empty!" << endl;
            exit(1);
        }
        else
        {
            return Head;
        }
    }

    // Uncomment if-needed for testing purposes
    // friend ostream& operator << (ostream& ostr, const LinkedList& list)
    // {
    //     cout << "BEGIN" << endl;
    //     LinkedListNode* Current = list.Head;
    //     while (Current != nullptr)
    //     {
    //         cout << Current->ID << "\t" 
    //             << Current->Payrate << "\t" 
    //             << Current->Name << "\t" 
    //             << Current->Hours << "\t$"
    //             << Current->Paycheck << endl;
    //         Current = Current->Next;
    //     }
    //     cout << "END";
    //     return ostr;
    // }

    // Comment-out & use code above for testing
    friend ostream& operator << (ostream& ostr, const LinkedList& list)
    {
        cout << "BEGIN" << endl;
        LinkedListNode* Current = list.Head;
        while (Current != nullptr)
        {
            cout << Current->Name << ", $" << Current->Paycheck << endl;
            Current = Current->Next;
        }
        cout << "END";
        return ostr;
    }
};

void sort_list(LinkedListNode* head);
void open_file(ifstream& input_file);
int main()
{   // Create list, which is currently empty
    LinkedList e;   

    //-----Open Employee Data File-----//
    ifstream employees_file;
    open_file(employees_file);
    cout << "File opened successfully!" << endl;
    cout << endl;
    //-----Open Employee Data File-----//

    //-----Read & Store Data-----//
    int id = 0;
    double payrate = 0.00;
    string name = "";

    while (employees_file >> id)
    {   // Read in data
        employees_file >> payrate;
        employees_file.ignore(9999, ' ');
        getline(employees_file, name);
        // Populate list with data
        e.PushBack(id, payrate, name);
    }

    employees_file.close();
    //-----Read & Store Data-----//

    // Uncomment if-needed for testing purposes
    // Test employees fill list properly before calculating hours worked and paycheck
    // cout << e << endl;

    //-----Open Hours Data File-----//
    cout << endl;   // Formatting
    ifstream hours_file;
    open_file(hours_file);
    cout << "File opened successfully!" << endl;
    cout << endl;
    //-----Open Hours Data File-----//

    //-----Read & Store Data-----//
    int emp_id = 0;
    int hours = 0;

    LinkedListNode* first = e.GetHead();  // Get first element in linked list

    while (hours_file >> emp_id)     // Read in employee ID
    {
        hours_file >> hours;        // Read in employee hours

        // Iterate through linked list comparing IDs
        for (LinkedListNode* itr = first; itr != nullptr; itr = itr->Next)
        {
            if (emp_id == itr->ID)   // If ID match is found, then calculate hours worked
            {
                itr->CalculateTotalHoursWorked(hours);
                itr->CalculatePayCheck();
            }
        }
    }

    hours_file.close();
    //-----Read & Store Data-----//

    // Uncomment if-needed for testing purposes
    // Test hours worked and paycheck calculations in employee list
    // cout << e << endl;

    // Sort the list according to highest paycheck and rank in descending order
    sort_list(first);

    cout << endl;   // Formatting
    cout << "***************PAYROLL INFORMATION***************" << endl;
    cout << e << endl;
    cout << "*************************************************" << endl;

    // Remember to Clear & Deallocate Memory!
    return 0;
}

void sort_list(LinkedListNode* head)
{
    LinkedListNode* current = head;
    LinkedListNode* next = nullptr;

    int tempID = 0;
    double tempRate = 0.00;
    string tempName = "";
    int tempHours = 0;
    double tempPay = 0.00;

    if (head == nullptr)
    {
        cout << "Empty list! Nothing to sort!" << endl;
        exit(1);
    }
    else
    {
        while (current != nullptr)
        {
            next = current->Next;
            while (next != nullptr)
            {
                if (current->Paycheck < next->Paycheck) // SWAP ALL THE THINGS!
                {
                    tempID = current->ID;
                    current->ID = next->ID;
                    next->ID = tempID;

                    tempRate = current->Payrate;
                    current->Payrate = next->Payrate;
                    next->Payrate = tempRate;

                    tempName = current->Name;
                    current->Name = next->Name;
                    next->Name = tempName;

                    tempHours = current->Hours;
                    current->Hours = next->Hours;
                    next->Hours = tempHours;

                    tempPay = current->Paycheck;
                    current->Paycheck = next->Paycheck;
                    next->Paycheck = tempPay;
                }
                next = next->Next;
            }
            current = current->Next;
        }
    }
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