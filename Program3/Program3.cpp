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
void collectUserInput(double &charge, double &threshold);
double validateNonNegative(double user_input);
double getFinalAccountBalance(double init_balance, double rate, double charge,
  double threshold, int table);
int getLengthToReachGoal(double init_balance, double rate, double charge,
  double threshold,
  int table, int period,
  double &final_balance);


int main() {
  double init_balance, rate, charge, threshold;
  int table, period;
  breifIntroForUser();
  collectUserInput(charge, threshold);
  return 0;
 }

 void breifIntroForUser() {
   cout << "The following program predicts the growth of a bank" << '\n';
   cout << "account due to compounded interest." << '\n' << endl;
 }

void collectUserInput(double &charge, double &threshold) {


  cout << "Please specify the bank's annual processing charge and threshold "
       << "in dollars." << '\n';
  cout <<  "Annual Processing Charge: $";
  cin  >> charge;
  cout << endl;
  validateNonNegative(charge);

  cout << "Threshold: $";
  cin  >> threshold;
  validateNonNegative(threshold);



}

double validateNonNegative(double user_input) {
  while(user_input <= 0) {
    cout << "Sorry, you must enter a value that is not negative. Thanks!"
         << endl << "Try again: $";
    cin  >> user_input;
    cout << endl;
  }
  return user_input;
}
