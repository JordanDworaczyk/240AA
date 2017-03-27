/**
* Jordan Dworaczyk
* CSC240AA
* Homework#7
* Due Monday, March 20
* Write a program to compute the demensions (width and height) of a screen
* given the diagonal and the aspect ratio (width divided by height).
*/

#include <iostream>
using namespace std;
#include <math.h>

struct Screen {
	double height;
	double width;
	double diagonal;
	double aspect_ratio;
};

Screen *computeDimensions(double diagonal, double aspect_ratio);

int main() {
	cout << "The follwoing program computes the demensions of a screen given the"\
	" diagonal and\nthe aspect ratio.\n\n";

	double diagonal, aspect_ratio, width, height;
	char again;
	Screen *demensions;

	do {

		cout << "Please enter the diagonal.\nEnter diagonal: ";
		cin  >> diagonal;
		cout << "Please enter the aspect ratio.\nEnter Aspect Ratio: ";
		cin  >> aspect_ratio;

		demensions = computeDimensions(diagonal, aspect_ratio);
		cout << "Width: " << demensions->width << endl;
		cout << "Height: " << demensions->height << endl;

		delete demensions;

		cout <<  "Would you like to go again?\n";
		cout << "Enter [y/n]: ";
		cin  >> again;

	} while(again == 'y');
	return 0;
}

Screen *computeDimensions(double diagonal, double aspect_ratio) {
	Screen *result = new Screen();
	double width;
	double height;

	height = sqrt( pow(diagonal, 2) / ( 1 + pow(aspect_ratio, 2)  ) );
	width = aspect_ratio * height;

	result->height = height;
	result->width = width;
	result->diagonal = diagonal;
	result->aspect_ratio = aspect_ratio;
	return result;
}
