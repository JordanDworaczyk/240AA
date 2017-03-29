/**
* Jordan Dworaczyk
* CSC240AA -- C++
* Program #7
* Due Wed. March 29
* Write a program to display the prime numbers within a given range of numbers.
*/

#include <iostream>
using namespace std;
#include <math.h>

void displayPrimes(int low_bound, int high_bound);
int *getList(int size);
int getFirstZero(int *list, int len);
void scanList(int *list, int size, int factor);
void convertZeros(int *list, int size);
int *getPrimes(int *list, int size, int &len);

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
	int size = (high_bound - low_bound);
	int first_zero, factor, len;
	int *list;
	int *primes;

	if(size == 0) {
		*list = high_bound;
	} else {
		list = getList(size);
	}

	for(int i = 0; i < size; i++) {
		first_zero = getFirstZero(list, size);

		factor = first_zero;
		scanList(list, size, factor);
	}
	convertZeros(list, size);
	primes = getPrimes(list, size, len);


	cout << "These are your primes!\n" << endl;
	for(int ix = 0; ix < len; ix++) {
		cout << primes[ix] << endl;
	}

	cout << "This is your list!" << endl;
	for(int ix = 0; ix < len; ix++) {
		cout << list[ix] << endl;
	}
	delete primes;
	delete list;
}

int *getList(int size) {
	int *list = new int[size];

	list[0] = -1;
	list[1] = -1;

	for(int i = 2; i <= size; i++) {
		list[i] = 0;
	}
	return list;
}

int getFirstZero(int *list, int len) {
	int index;

	for(int ix = 0; ix < len; ix++) {

		if(list[ix] == 0) {
			index = ix;
		}
	}
	return index;
}

void scanList(int *list, int size, int factor) {

	int start = getFirstZero(list, size);
	list[start] = 1;

	for(int index = start + factor; index < size; index = index + factor ) {
		if(0 == index % factor) {
			list[index] = -1;
		}
	}
}

void convertZeros(int *list, int size) {
	for(int ix = 0; ix < size; ix++) {
		if(list[ix] == 0) {
			list[ix] = 1;
		}
	}
}

int *getPrimes(int *list, int size, int &len) {
	int index = 0;
	int count = 0;

	for(int ix = 0; ix < size; ix++) {
		if(list[ix] == 1){
			count++;
		}
	}

	len = count;
	int *primes = new int[len];

	for(int ix = 0; ix < size; ix++ ) {
		if(list[ix] == 1) {
			primes[index] = ix;
			index++;
		}
	}

	return primes;
}
