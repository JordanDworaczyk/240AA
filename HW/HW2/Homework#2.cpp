/**
 * Jordan Dworaczyk
 * CSC240AA - Homework#2 - C++
 * Due Monday, January 30
 * Write FOUR subprograms to do several different tasks.
 */

 #include <iostream>
 using namespace std;
 #include <math.h>

 void introduction(void);
 void collectInput(double &ringRadius, double &crossSectionRadius);
 double getVolume(double ringRadius, double crossSectionRadius);
 void displayResult(double volume);

 int main( ) {
   double ringRadius, crossSectionRadius, volume;

   introduction();
   collectInput(ringRadius, crossSectionRadius);
   volume = getVolume(ringRadius, crossSectionRadius);
   displayResult(volume);
   return 0;
 }

 void introduction(void) {
   cout << "Computing Ring Volume" << endl << endl;;
 }

 void collectInput(double &ringRadius, double &crossSectionRadius) {
   cout << "Please enter a ring radius and cross section radius both in inches"
        <<  endl;
   cout << "They must both be positive!" << endl;
   cout << "Enter ring radius here: ";
   cin >> ringRadius;
   cout << endl;

   while(ringRadius < 0) {
     cout << "The nuumber you entered was less than zero!" << endl
     << "Please enter a new number: " << endl;
     cin >> ringRadius;
   }
   cout << "Enter cross section radius here: ";
   cin >> crossSectionRadius;
   cout << endl;

   while(crossSectionRadius < 0) {
     cout << "The nuumber you entered was less than zero!" << endl
     << "Please enter a new number: " << endl;
     cin >> crossSectionRadius;
   }

 }

 double getVolume(double ringRadius, double crossSectionRadius) {
   double volume;
   const double PI = 3.14159;

   volume = (2 * pow(PI, 2) * (ringRadius * ( pow(crossSectionRadius, 2))));
   return volume;
 }

 void displayResult(double volume) {
   cout << "The volume of the ring is " << volume << " inches" << endl;
 }
