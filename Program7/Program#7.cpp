/**
* Jordan Dworaczyk
* CSC240AA -- C++
* Program #7
* Due Wed. March 29
* Write a program to display the prime numbers within a given range of numbers.
*/

#include <iostream>
using namespace std;

void displayPrimes(int low_bound, int high_bound);
int *getList(int size);
int getFirstZero(int *list, int len);

int main() {
	char response;
	int low_bound, high_bound;

	cout << "The following program displays the prime numbers within" << endl
			 << "a given range of numbers." << endl;

	do {
		cout << "Please specify a range of positive intgers with a low" << endl
				 << "and high boundary.\n" << endl;

		do {
			cout << "Enter Low Boundary: ";
			cin  >> low_bound;

			cout << "\nPlease Enter High Boundary: ";
			cin  >> high_bound;

			if(!(low_bound > 0 && high_bound >= low_bound)) {
				cout << "\nMake sure that you are entering only positive numbers and"
				     << "that your higher bound is greater than your lower bound.\n";
			}

		} while(!(low_bound > 0 && high_bound >= low_bound));

	displayPrimes(low_bound, high_bound);
	//collectRespose();

		cout << "Would you like to repeat?" << endl;
		cout << "Enter [y/n]: ";
		cin  >> response;
	} while(response == 'y' || response == 'Y');

	cout << "All done!";
	return 0;
}

void displayPrimes(int low_bound, int high_bound) {
	int size = high_bound - low_bound;
	int first_zero;
	int *list;

	if(size == 0) {
		*list = high_bound;
	} else {
		list = getList(size);
	}

	first_zero = getFirstZero(list, size);
}

int *getList(int size) {
	int *list = new int[size];

	list[0] = -1;
	list[1] = -1;

	for(int i = 2; i < size; i++) {
		list[i] = 0;
	}
	return list;
}

int getFirstZero(int *list, int len) {
	int element, index;
	index = 1;
	do {
		element = list[1];
		index++;
	} while(element != 0);

	return index;
}
