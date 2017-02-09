/**
 * Jordan Dworaczyk
 * CSC240AA - Program#3 - C++
 * Due Wednesday, February 8
 * Prgram predicts the growth of a bank account due to compounded interest.
 */

#include <iostream>
using namespace std;
#include <math.h>
#include <stdio.h>

void breifIntroForUser(void);
void collectUserInput(double &charge, double &threshold, double &init_balance,
                      double &rate, int &period, int &choice);
double collectCharge(void);
double collectThreshold(void);
double collectInitBalance(void);
double collectRate(void);
int collectPeriod(void);
int collectChoice(int period);
double validateNonNegative(double user_input);
int validatePeriod(int user_input);
void printPeriod(int period);
void printChoice(int choice);
int validateChoice(int choice);
void accountSummary(double init_balance, double rate, double charge,\
    double threshold,
    int period,
    int choice);
int requestTable(void);
double getFinalAccountBalance(double init_balance, double rate, double charge,
    double threshold, int is_table, int length_of_investment);
int getLengthToReachGoal(double init_balance, double rate, double charge,
    double threshold,
    int period, int is_table,
    double &final_balance);


int main() {

  double init_balance, rate, charge, threshold, final_balance, amount;
  int period, choice, is_table, length_of_investment;
  breifIntroForUser();

  int user_input;
  collectUserInput(charge, threshold, init_balance, rate, period, choice);
  //accountSummary(init_balance, rate, charge, threshold, period, choice);

  if(choice == 0){

    cout << endl << "Please, specify the length of the investment." << endl;
    cout << "Enter the amount of ";
    printPeriod(period);
    cout << ":";
    cin  >> length_of_investment;
    cout << endl;
    
    is_table = requestTable();

    final_balance =
        getFinalAccountBalance(init_balance, rate, charge, threshold,
        is_table, length_of_investment);
    cout << "The final balance of your account is $" << final_balance
         << " after " << length_of_investment << " ";
    printPeriod(period);
    cout << "." << endl;
  } else {

    cout << endl << "Please, specify the amount you would like to achieve.\n"
         << "Enter the amount: $";
    cin  >> amount;
    amount = validateNonNegative(amount);
    cout << endl;

    is_table = requestTable();


    length_of_investment =
        getLengthToReachGoal(init_balance, rate, charge, threshold, period,
        is_table, amount);

    cout << "You reached your goal afer " << length_of_investment << " ";
    printPeriod(period);
    cout << " with a final total balance of \n$" << amount << endl;
  }

  do {

  cout << endl << "Would you like to do another calculation (with the same \n"
       << "processing charge and threshold)?\n" << "Please, enter your choice "
       << "(0 for no & 1 for yes): ";
  cin  >> user_input;
  user_input = validateChoice(user_input);
  cout << endl;

  if(user_input == 1) {
    init_balance = collectInitBalance();
    rate = collectRate();
    period = collectPeriod();
    choice = collectChoice(period);
    is_table = requestTable();

    if(choice == 0) {
      final_balance =
          getFinalAccountBalance(init_balance, rate, charge, threshold,
          is_table, length_of_investment);
      cout << "\nThe final balance of your account is $" << final_balance
           << " after " << length_of_investment << " ";
      printPeriod(period);
      cout << "." << endl << endl;

  } else {

      length_of_investment =
          getLengthToReachGoal(init_balance, rate, charge, threshold, period,
          is_table, amount);

      cout << "\nYou reached your goal afer " << length_of_investment << " ";
      printPeriod(period);
      cout << " with a final total balance of \n$" << amount << endl << endl;
    }

  } else {

    cout << "Would you rather try a different processing charge and threshold?"
     << endl << "Enter 0 for yes & 1 for no: ";
    cin  >> user_input;
    user_input = validateChoice(user_input);
    cout << endl;

    if(user_input == 1) {
      charge = collectCharge();
      threshold = collectThreshold();
      is_table = requestTable();

      if(choice == 0) {
        final_balance =
            getFinalAccountBalance(init_balance, rate, charge, threshold,
            is_table, length_of_investment);
        cout << "\nThe final balance of your account is $" << final_balance
             << " after " << length_of_investment << " ";
        printPeriod(period);
        cout << "." << endl << endl;

      } else {

        length_of_investment =
            getLengthToReachGoal(init_balance, rate, charge, threshold, period,
            is_table, amount);

        cout << "\nYou reached your goal afer " << length_of_investment << " ";
        printPeriod(period);
        cout << " with a final total balance of \n$" << amount << endl << endl;
      }
    }
  }
} while(user_input != 0);

  cout << "Thats all folks!" << endl;
  return 0;
 }

 void breifIntroForUser() {
   cout << "The following program predicts the growth of a bank" << '\n';
   cout << "account due to compounded interest." << '\n' << endl;
 }

void collectUserInput(double &charge, double &threshold, double &init_balance,
                      double &rate, int &period, int &choice) {

  charge = collectCharge();
  threshold = collectThreshold();
  init_balance = collectInitBalance();
  rate = collectRate();
  period = collectPeriod();
  choice = collectChoice(period);
}

double collectCharge(void){
  double charge;
  cout << "Please specify the bank's annual processing charge and threshold "
       << "in dollars." << '\n';
  cout <<  "Enter Annual Processing Charge: $";
  cin  >> charge;
  charge = validateNonNegative(charge);
  return charge;
}
double collectThreshold(void) {
  double threshold;
  cout << "Enter Threshold: $";
  cin  >> threshold;
  threshold = validateNonNegative(threshold);
  return threshold;
}
double collectInitBalance(void){
  double init_balance;
  cout << endl;
  cout << "Please specify the initial account balance in dollars." << endl;
  cout << "Enter initial account ballance: $";
  cin  >> init_balance;
  cout << endl;
  init_balance = validateNonNegative(init_balance);
  return init_balance;
}
double collectRate(void){
  double rate;
  cout << "Please enter the annual interest rate." << endl;
  cout << "Enter annual interest rate: ";
  cin  >> rate;
  cout << endl;
  rate = validateNonNegative(rate);
  return rate;
}
int collectPeriod(void){
  int period;
  cout << "Please enter the period at which the interest is compounded." <<endl;
  cout << "If daily, then enter a zero  (i.e 0)." << endl;
  cout << "If monthly, then enter a one (i.e 1)." << endl;
  cout << "If yearly, then enter a two  (i.e 2)." << endl;
  cout << "Enter period: ";
  cin  >> period;
  cout << endl;
  period = validatePeriod(period);
  return period;

}
int collectChoice(int period){
  int choice;
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
  cout << " it will take to achieve that ammount.";
  cout << endl;
  cout << endl << "Please enter 0 for A, or enter 1 for B." << endl;
  cout << "Enter choice (0 or 1): ";
  cin  >> choice;
  choice = validateChoice(choice);
  return choice;
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
  return user_input;
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

void printChoice(int choice) {
  int choiceA = 0;
  int choiceB = 1;

  if (choiceA == 0) {
    cout << "A" << endl;
  } else {
    cout << "B" << endl;
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

void accountSummary(double init_balance, double rate, double charge,\
    double threshold, int period, int choice) {
  cout << endl;
  cout << "Account summary:" << endl;
  cout << "Annual Processing Charge: $" << charge << endl;
  cout << "Threshhold: $" << threshold << endl;
  cout << "Initial Account Balance: $" << init_balance << endl;
  cout << "Interest Rate: " << rate << "%" << endl;
  cout << "Period Compounded Over: ";
  printPeriod(period);
  cout << endl << "Choice: ";
  printChoice(choice);
  cout << endl;
}

int requestTable() {
  int user_input;
  cout << "\nWould you like a table of each decribing the account balance "
       << "at the end of each period?\n" << "Enter 0 for no and 1 for yes: ";
  cin  >> user_input;
  user_input = validateChoice(user_input);
  return user_input;
}

double getFinalAccountBalance(double init_balance, double rate, double charge,
    double threshold, int is_table, int length_of_investment ) {
  //for debugging
  /*cout << endl <<  "init_balance: " << init_balance << endl;
  cout << "rate: " << rate << endl;
  cout << "charge: " << charge << endl;
  cout << "threshold: " << threshold << endl;
  cout << "is_table: " << is_table << endl;
  cout << "length_of_investment: " << length_of_investment << endl << endl;*/

  int i;
  double balance = init_balance;
  double interest, temp_balance;
  for(i = 0; i < length_of_investment; i++) {

    if(balance < threshold) {
      balance = balance - charge;
      //cout << endl << "balance after penalty: " << balance << endl; //debugging
    }
    interest = balance * (rate / 100);
    //cout << endl << "interest: " << interest << endl; //debugging
    temp_balance = balance + interest;
    //cout << "new balance: " << temp_balance << endl; //debugging
    balance = temp_balance;
    //cout << endl << "balance: " << balance << endl; //debugging

    if(is_table == 1) {
      printf("%*.2f ", 3 , balance);

      int n;
      for(n = 0; n < i; n++) {
        cout << "*";
      }
    cout << endl;
    }

  }
  cout << endl << endl;

  return balance;
}

int getLengthToReachGoal(double init_balance, double rate, double charge,
    double threshold,
    int period, int is_table,
    double &amount) {

  if(is_table == 1) {
    is_table = 2;
  }
  int length_of_investment = 1;
  while(length_of_investment) {
    double balance =
        getFinalAccountBalance(init_balance, rate, charge, threshold,
        is_table,length_of_investment);
    //cout << "balance: " << balance << endl; //debugging

    if(balance >= amount) {
      amount = balance;
      if(is_table == 2) {
        is_table = 1;
      }
      return length_of_investment;
    } else {
      length_of_investment++;
    }

    if(is_table == 2) {
      printf("%*.2f ", 3 , balance);

      int n;
      for(n = 1; n < length_of_investment; n++) {
        cout << "*";
      }
    cout << endl;
    }

  }

  if(is_table == 2) {
    is_table = 1;
  }
  return 0;
}
