/* Jordan Dworaczyk
 * CSC240AA - HW #1 - C++
 * Due Wed. Jan 25
 * Write a C++ program to compute the total volume of N spheres, where N
 * is a number entered by the user. For each shpere, ask for the radius,
 * compute the volume, and add that volume to the total. The radius can only
 * be a positive number.
 */

 #include <iostream>
 using namespace std;
 #include <math.h>

 int main()
 {
   int n;
   double radius;
   double volume = 0;
   const double PI = 3.14159;

   cout << "How many spheres would you like to find the total volume for?" << endl;
   cin >> n;

   for(int i = 0; i < n; i++) {
    cout << "Enter the radius of sphere number " << i + 1 << endl << "(The radius"
         << " must be a positive number)" << endl << "Enter number: ";
    cin  >> radius;
    cout << endl;

    while (radius < 0) {
      /* force user to input a positve number */
      cout << "Sorry. The number you entered was less then zero. Please enter a" << '\n';
      cout << "positve number." << endl;
      cin >> radius;
    }

    volume = volume + ( (4/3) * PI * (pow(radius, 3) ) );
   }
   cout << "The total volume is " << volume << endl;
   return 0;
 }
