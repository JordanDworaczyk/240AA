/**
 * Jordan Dworaczyk
 * CSC240AA - Program#3 - C++
 * Due Wednesday, February 8
 * Prgram predicts the growth of a bank account due to compounded interest.
 */

#include <iostream>
using namespace std;
#include <math.h>

void breifIntroForUser(void);
void collectUserInput(double &charge, double &threshold, double &init_balance,
                      double &rate, int &period, int &choice);
double validateNonNegative(double user_input);
int validatePeriod(int user_input);
void printPeriod(int period);
int validateChoice(int choice);
double getFinalAccountBalance(double init_balance, double rate, double charge,
  double threshold, int table);
int getLengthToReachGoal(double init_balance, double rate, double charge,
    double threshold,
    int table, int period,
    double &final_balance);


int main() {
  double init_balance, rate, charge, threshold;
  int table, period, choice;
  breifIntroForUser();
  collectUserInput(charge, threshold, init_balance, rate, period, choice);
  return 0;
 }

 void breifIntroForUser() {
   cout << "The following program predicts the growth of a bank" << '\n';
   cout << "account due to compounded interest." << '\n' << endl;
 }

void collectUserInput(double &charge, double &threshold, double &init_balance,
                      double &rate, int &period, int &choice) {


  cout << "Please specify the bank's annual processing charge and threshold "
       << "in dollars." << '\n';
  cout <<  "Enter Annual Processing Charge: $";
  cin  >> charge;
  charge = validateNonNegative(charge);

  cout << "Enter Threshold: $";
  cin  >> threshold;
  threshold = validateNonNegative(threshold);

  cout << endl;
  cout << "Please specify the initial account balance in dollars." << endl;
  cout << "Enter initial account ballance: $";
  cin  >> init_balance;
  cout << endl;
  init_balance = validateNonNegative(init_balance);

  cout << "Please enter the annual interest rate." << endl;
  cout << "Enter annual interest rate: ";
  cin  >> rate;
  cout << endl;
  rate = validateNonNegative(rate);

  cout << "Please enter the period at which the interest is compounded." <<endl;
  cout << "If daily, then enter a zero  (i.e 0)." << endl;
  cout << "If monthly, then enter a one (i.e 1)." << endl;
  cout << "If yearly, then enter a two  (i.e 2)." << endl;
  cout << "Enter period: ";
  cin  >> period;
  cout << endl;
  period = validatePeriod(period);

  cout << endl;
  cout << "Please select one of the two options:" << endl;
  cout << "(A) Enter the length in ";
  printPeriod(period);
  cout << " that ";
  cout << "you would like your account to be invested," << endl;;
  cout << "so that you can find the final balance of your account for the ";
  cout << "given duration.";
  cout << endl << endl << "or" << endl << endl;
  cout << "(B) Specify a goal for the account balance, and have the" << endl;
  cout << "program calculate how long in ";
  printPeriod(period);
  cout << " it will take to achieve that amount.";
  cout << endl;
  cout << endl << "Please enter 0 for A, or enter 1 for B." << endl;
  cout << "Enter choice (0 or 1): ";
  cin  >> choice;
  choice = validateChoice(choice);;
}

double validateNonNegative(double user_input) {
  while(user_input < 0) {
    cout << endl;
    cout << "Sorry, you must enter a value that is not negative. Thanks!"
         << endl << "Try again: $";
    cin  >> user_input;
    cout << endl;
  }
  return user_input;
}

int validatePeriod(int user_input) {

  while(user_input < 0 || user_input > 2) {
    cout << "Sorry you must enter numbers 0, 1, or 2." << endl;
    cout << "Enter period: ";
    cin  >> user_input;
  }
  return 0;
}

void printPeriod(int period) {
  int daily = 0;
  int monthly = 1;
  int yearly = 2;

  if(daily == period) {
    cout << "days";
  } else if(monthly == period) {
    cout << "months";
  } else {
    cout << "years";
  }
}

int validateChoice(int choice) {
  while(choice < 0 || choice > 1) {
    cout << "Sorry you must enter number 0 or 1." << endl;
    cout << "Enter choice: ";
    cin  >> choice;
  }
  return choice;
}
