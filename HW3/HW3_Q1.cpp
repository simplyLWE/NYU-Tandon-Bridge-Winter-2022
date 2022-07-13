/* 

Assignment:
-----------

Write a program that computes how much a customer has to pay after purchasing two items.
The price is calculated according to the following rules:
• Buy one get one half off promotion: the lower price item is half price.
• If the customer is club card member, additional 10% off.
• Tax is added.

Inputs to the program include:
• Two items’ prices
• Have club card or not (User enters ‘Y’ or ‘y’ for “yes”; ‘N’ or ‘n’ for “no”)
• Tax rate (User enters the percentage as a number; for example they enter 8.25 if the tax rate is 8.25%)

Program displays:
• Base price - the price before the discounts and taxes
• Price after discounts - the price after the buy one get one half off promotion and the member’s discount, if applicable
• Total price – the amount of money the customer has to pay (after tax).

Your program should interact with the user exactly as it shows in the following example:

Enter price of first item: 10
Enter price of second item: 20
Does customer have a club card? (Y/N): y
Enter tax rate, e.g. 5.5 for 5.5% tax: 8.25
Base price: 30.0
Price after discounts: 22.5
Total price: 24.35625

*/

#include <iostream>
using namespace std;

// Constant var for club membership
const double CLUB_MEMBER_DISCOUNT = 0.10;

int main()
{
  // Vars for user input
  double item_price1 = 0;
  double item_price2 = 0;
  char club_member_card = '\0';
  double tax_rate = 0;

  // Prompt user for input
  cout << "Enter price of first item: ";
  cin >> item_price1;
  cout << "Enter price of second item: ";
  cin >> item_price2;
  cout << "Does customer have a club card? (Y/N): ";
  cin >> club_member_card;
  cout << "Enter tax rate, i.e. 5.5 for 5.5% tax: ";
  cin >> tax_rate;

  // Calculate base price before discounts and taxes
  double base_price = item_price1 + item_price2;
  cout << "Base price: " << base_price << endl;

  // Calculate 'buy one get one (bogo) half off' discount price
  // Lowest price item is half price
  double bogo_discount = 0;
  if (item_price1 < item_price2)
  {
    bogo_discount = item_price2 + (item_price1 / 2);
  }
  else if (item_price2 <= item_price1)
  {
    bogo_discount = item_price1 + (item_price2 / 2);
  }

  // Calculate bogo discount with club member discount price
  double bogo_with_club_member_discount = bogo_discount * CLUB_MEMBER_DISCOUNT;

  // Calculate price after all discounts
  double all_price_discounts = bogo_discount - bogo_with_club_member_discount;
  cout << "Price after discounts: " << all_price_discounts << endl;

  // Apply discounts to calculate final price, depending on club member
  double final_price = 0;
  if (club_member_card == 'y' || club_member_card == 'Y')
  {
    final_price = all_price_discounts + (all_price_discounts * (tax_rate / 100));
  }
  else if (club_member_card == 'n' || club_member_card == 'N')
  {
    final_price = bogo_discount + (bogo_discount * (tax_rate / 100));
  }

  cout << "Total price: " << final_price << endl;

  return 0;
}