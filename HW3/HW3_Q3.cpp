/* 

Assignment:
-----------

Write a program that does the following:
• Ask user to input three Real numbers a, b and c. They represent the parameters of a quadratic equation ax^2 + bx + c = 0
• Classify to one of the following:
  - 'Infinite number of solutions' (for example, 0x^2 + 0x + 0 = 0 has infinite number of solutions)
  - 'No solution' (for example, 0x^2 + 0x + 4 = 0 has no solution)
  - 'No real solution' (for example, x^2 + 4 = 0 has no real solutions)
  - 'One real solution'
  - 'Two real solutions'
• In cases there are 1 or 2 real solutions, also print the solutions.

Notes:
1. If a ≠ 0 and there are real solutions to the equation, you can get these solutions using the following formula:
    
    x1,2 = -b ± √ (b^2 - 4ac) / 2a

    The number of solutions depends on whether (b^2 - 4ac) is positive, zero, or negative.

2. In order to calculate the square root of a number (of type double), you should call the sqrt function, located in the cmath library.

    Follow the syntax as demonstrated in the code below:
  
    #include <iostream>
    #include <cmath>
    using namespace std;
  
    int main() {
      double x = 2.0;
      double sqrtResult;

      sqrtResult = sqrt(x);
      cout<<sqrtResult<<endl;

      return 0;
    }

    Note that you first need to include the cmath library,
    and then you can call the sqrt function, passing the argument that you want to calculate the square root of, enclosed in parentheses.

Your program should interact with the user exactly as it shows in the following example:

Please enter value of a: 1
Please enter value of b: 4
Please enter value of c: 4
This equation has a single real solution x = -2.0

*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  // Vars for user input
  double a = 0;
  double b = 0;
  double c = 0;

  // Prompt user for 3 real numbers
  cout << "Please enter value of a: ";
  cin >> a;
  cout << "Please enter value of b: ";
  cin >> b;
  cout << "Please enter value of c: ";
  cin >> c;

  // Formatting
  cout << endl;

  // Consider the case when a is 0
  if (a == 0 && b == 0 && c == 0)
  {
    cout << "This equation has infinitely many solutions." << endl;
  }
  else if (a == 0 && b == 0 && c != 0)
  {
    cout << "This equation has no solutions." << endl;
  }
  else if (a == 0 && b != 0 && c != 0 || a == 0 && b != 0 && c == 0)
  {
    cout << "This equation is an undefined quadratic equation; it is no longer quadratic, and instead becomes a linear equation. The quadratic formula cannot be applied in this case." << endl;
  }

  // Consider the case when a is not 0
  if (a != 0)
  {
    // Calculate discriminant
    double discriminant = (b*b - 4*a*c);

    // Vars for possible solutions
    double x1 = 0;
    double x2 = 0;

    // If discriminant > 0, solutions are real and different
    if (discriminant > 0)
    {
      x1 = ((-1)*b + sqrt(discriminant))/(2*a);
      x2 = ((-1)*b - sqrt(discriminant))/(2*a);
      
      cout << "This equation has two real solutions: "
      << "x = " << x1 << " and x = " << x2 << endl;
    }

    // If discriminant is = 0, solutions are real and equal
    if (discriminant == 0)
    {
      x1 = ((-1)*b)/(2*a);
      cout << "This equation has one real solution: x = " << x1 << endl;
    }

    // If discriminant is < 0, solutions are complex and different
    if (discriminant < 0)
    {
      cout << "This equation has no real solution." << endl;
    }
  }

  return 0;
} 