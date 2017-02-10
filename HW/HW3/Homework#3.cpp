/**
* Jordan Dworaczyk
* CSC240AA -- C++
* Homeork#3
* Due Wed. Feb. 8th
* Write a program in C++ to manipulate arrays.
*/
#include <iostream>
using namespace std;

int *collectUserArray(int &array_length);
int *findMatchingIntegers(int list_given[], int list_size, int target
    ,int &total_matches);
int displayArray(int user_array[], int array_size);

int main() {
  int *user_array;
  int *list_given;
  int list_size, total_matches, target;

  user_array = collectUserArray(list_size);
  displayArray(user_array, list_size);

  list_size = 5;
  target = 1;
  list_given = new int[list_size];
  list_given = findMatchingIntegers(list_given, list_size, target
      ,total_matches);

  return 0;
}

int *collectUserArray(int &array_length) {
  int user_input;
  int *list_integers;

  cout <<"How big do you want the array to be?\n";
  do {
    cout << "Enter array size: ";
    cin  >> user_input;
    cout << endl;
  } while(user_input < 0);

  array_length = user_input;
  list_integers = new int[array_length];
  if(array_length != 0 ) {
    cout << "Please, enter your integers into the array.\n";
    for(int i = 0; i < array_length; i++) {
      cout << "Enter Integers: ";
      cin  >> user_input;

      list_integers[i] = user_input;
    }
  } else {
    cout << "Array size of zero. Thats all folks!\n";
    return 0;
  }
  cout << endl;
  return list_integers;
}

int displayArray(int user_array[], int array_size) {

  if(array_size > 0) {
    cout << "List given: \n[ ";
    for(int i = 0; i < array_size; i++) {
      cout << user_array[i] << " ";
    }
    cout << "]" << endl;
  }

  return 0;
}

int *findMatchingIntegers(int list_given[], int list_size,  int target
    ,int &total_matches) {

  int *matches;
  matches = new int[list_size];

  for(int i = 0; i < list_size; i++ ) {

  }

  return 0;
}
