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
  int *list_of_matches;
  int list_size, total_matches, target, user_choice;

  user_choice = 1;

  while(user_choice == 1) {
    user_array = collectUserArray(list_size);
    //displayArray(user_array, list_size);

    while(user_choice == 1) {
      cout << "\nWhat integer would you like to search for?\nEnter Integer: ";
      cin  >> target;
      cout << endl;


        list_of_matches = findMatchingIntegers(user_array, list_size, target
            ,total_matches);
        displayArray(list_of_matches, total_matches);
        cout << endl;
        cout << "Would you like to continue looking for matches?\nEnter 1 for "
             << " yes enter 0 for no: ";
        cin  >> user_choice;
    }
    cout << endl;
    cout << "Would you like to do it again for another list?\nEnter 1 for yes"
         << " and 0 for no: ";
    cin  >> user_choice;
    cout << endl;
  }
  cout << "\nThat's all folks!\n";
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
    cout << "Array size of zero.\n";
    return 0;
  }
  cout << endl;
  return list_integers;
}

int displayArray(int user_array[], int array_size) {

  if(array_size > 0) {
    cout << "Matching array: \n[ ";
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
  total_matches = 0;

  for(int i = 0; i < list_size; i++ ) {
    int test = list_given[i];
    if(test == target) {
      total_matches++;
    }
  }

  matches = new int[total_matches];
  total_matches = 0;

  for(int i = 0; i < list_size; i++) {
    int test = list_given[i];
    if(test == target) {
      matches[total_matches] = i;
      total_matches++;
    }
  }

  if(total_matches != 0) {
    return matches;
  }

  return 0;

}
