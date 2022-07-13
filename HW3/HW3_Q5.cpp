/*

Assignment:
-----------

Body mass index (BMI) is a number calculated from a person’s weight and height using the following formula: weight/height^2.
Where weight is in kilograms and height is in meters.

According to the Centers for Disease Control and Prevention, the BMI is a fairly reliable indicator of body fatness for most people.
BMI does not measure body fat directly, but research has shown that BMI correlates to direct measures of body fat,
such as underwater weighing and dual-energy X-ray absorptiometry.

The following table gives the weight status in respect to the BMI value:
 
BMI Range      | Weight Status
---------------|--------------
Below 18.5     | Underweight
[18.5, 25)     | Normal
[25, 30)       | Overweight
30 and above   | Obese

Write a program that prompts for weight (in pounds) and height (in inches) of a person, and prints the weight status of that person.

Your program should interact with the user exactly as it shows in the following example:

Please enter weight (in pounds): 135
Please enter height (in inches): 71
The weight status is: Normal

Note: 1 pound is 0.453592 kilograms and 1 inch is 0.0254 meters.
   
*/

#include <iostream>
using namespace std;

// Constants to convert standard measurements to metric 
const double LB_PER_KILO = 0.453592;
const double INCH_PER_METER = 0.0254;

int main()
{
  // Vars for user input
  double weight = 0;
  double height = 0;

  // Get weight from user
  cout << "Please enter weight (in pounds): ";
  cin >> weight;
  if (weight <= 0)
  {
    cout << "Please enter a valid weight: ";
    cin >> weight;
  }
  
  // Get height from user
  cout << "Please enter height (in inches): ";
  cin >> height;
  if (height <= 0)
  {
    cout << "Please enter a valid height: ";
    cin >> height;
  }

  // Convert height & weight to metric
  double metric_weight = weight * LB_PER_KILO;
  double metric_height = height * INCH_PER_METER;

  // Calculate user's bmi
  double bmi = metric_weight / (metric_height * metric_height);

  // Print weight status to user
  if (bmi < 18.5)
  {
    cout << "The weight status is: Underweight" << endl;
  }
  else if (bmi >= 18.5 && bmi < 25)
  {
    cout << "The weight status is: Normal" << endl;
  }
  else if (bmi >= 25 && bmi < 30)
  {
    cout << "The weight status is: Overweight" << endl;
  }
  else if (bmi >= 30)
  {
    cout << "The weight status is: Obese" << endl;
  }

  return 0;
} 