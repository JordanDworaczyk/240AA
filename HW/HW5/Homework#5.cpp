/**
* Jordan Dworaczyk
* CSC240AA -- C++
* Homework#5
* Due Wed. Feb. 22nd
* Write subprograms that are given: an array of integers, the number of
* integers, and a target for a search, and return the number of matches with
* the given search target.
*
* Write one subprgram that uses array indexing, and a second subprogram that
* replaces all array indexing with direct pointer incrementing. */
#include <iostream>
using namespace std;

const int MAXSIZE = 100;

int loadData(int *num);
int search(int *num, int target, int len);
int pSearch(int *num, int target, int len);
int collectTarget();

int main() {
	int *num = new int[MAXSIZE];
	int len, matches, target;

	cout << "The following program returns the number of matches that are in an\n"
	     << "array given by the user. the first method is using array indexing,\n"
			 << "and the second method uses array  indexing with direct pointer\n"
			 << "incrementing.\n\n";
	len = loadData(num);
	target = collectTarget();

	cout << "(1) First result is returned using array indexing...\n\n";
	matches = search(num, target, len);
	cout << "(1) There are " << matches << " " << target << "'s\n\n";
	matches = pSearch(num, target, len);
	cout << "(2) Second result is returned using array indexing with direct \n"
			 << "pointer incrementing.\n\n";
	matches = pSearch(num, target, len);
	cout << "(2) There are " << matches << " " << target << "'s\n\n";
}

int loadData(int *num) {
	char again;
	int ix = 0;
	do {
		cout <<"Enter a number: ";
		cin  >> num[ix];
		ix++;

		cout << "Another (y/n)? ";
		cin  >> again;
	}while (again == 'y');
	return ix;
}

int search(int *num, int target, int len) {
	int matches = 0;

	for(int ix = 0; ix < len; ix++) {
		if(target == num[ix]) {
			matches++;
		}
	}
	return matches;
}

int collectTarget() {
	int target;
	cout << "Enter the target integer: ";
	cin  >> target;
	return target;
}

int pSearch(int *num, int target, int len) {
	int matches = 0;
	int *plength = num + len;
	while(num < plength) {
		if(*num == target) {
			matches++;
		}
		num++;
	}
	num = num - len;
	return matches;
}
