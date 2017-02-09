/**
* Jordan Dworaczyk
* CSC240AA -- C++
* Homeork#3
* Due Wed. Feb. 8th
* Write a program in C++ to manipulate arrays.
*/
#include <iostream>
using namespace std;

int *collectUserArray(void);
int *findMatchingIntegers(int list_given[], int list_size, int target);

int main() {
  int *user_array;
  user_array = collectUserArray();



  return 0;
}

int *collectUserArray(void) {
  int user_input, array_length;
  int *list_integers;

  cout <<"How big do you want the array to be?\n";
  do {
    cout << "Enter array size: ";
    cin  >> user_input;
    cout << endl;
  } while(user_input < 0);

  array_length = user_input;
  list_integers = new int[array_length];

  cout << "Please, enter your integers into the array.\n";
  for(int i = 0; i < array_length; i++) {
    cout << "Enter Integers: ";
    cin  >> user_input;

    list_integers[i] = user_input;
  }
  cout << endl;
  return list_integers;
}

/*
int *findMatchingIntegers(int list_given[], int list_size,  int target) {
  int *matches;
  matches = new int[list_size];

  for(int i = 0; i < list_size; i++ ) {

  }

  return 0;
}*/
