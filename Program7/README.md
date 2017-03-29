# Assignment
Write a program to display the prime numbers within a given range of numbers.

## The interface:

Display a title, then ask the user to specify a range of positive integers with
a low and high boundary. For each entry, repeat until the user enters a
positive number. After a positive high boundary is entered, test for low boundary less than or equal to the high boundary, and, if it is not, repeat the process of entering both boundaries.

After the boundaries are set, display a list of the prime numbers that are within that range (inclusive).

After displaying the primes, ask the user if they want to do it again. If they do, then repeat the process (ask for boundaries and display the primes). Otherwise, exit the program.

## algorithm:
Use a variation of what is called the "Sieve of Eratosthenes":

To find the primes up to a given integer N.
1. List all the intgers from 1 to N, and cross out 1.
2. Find the first integer that is not circled or crossed out out, and circle it.
3. If that number is greater than the square root of N, then skip to step 6.
4. Cross out all multiples of the circled number (greater than the number).
5. Go back to step 2.
6. Cirlce all remaining numbers that are not crossed out of circled.
7. The numbers that are cirlced are prime.

## The implementation:
Use an array, with the indexes of each element corresponding to the integers. (For simplicity, include the element at index zero also.) In each element of the array, use an integer code to represent the status:

	* -1 means not a prime (crossed out)
	* +1 means a prime (circled)
	* 0 means unkown (not yet crossed or circled)

## Create the following subprograms:
* 
	* Given an integer size, return an array of integers of that size, with all elements initialized to zero, except for elements at indexes 0 and 1, that are set to 'NOT PRIME' (-1). (Use the 'return' statement to return the new array.)
	* Given an array of integers, and the size of that array, return the index of the first element that contains a zero (Use the 'return' statement.)
	* Given an array of integers, the size of that array, and an integer factor, 'circle' the element at the index equal to the given factor (store +1 there), then scan the rest of the array and 'cross out' (mark with a -1) every other element with an index that is a multiple of the given factor. (Use the factor to 'skip' through the array instead of visiting each element.)
	* Given an array of integers, and the size of that array, scan the array and convert every element that contains a zero (unknown) to a +1 (circled).
	* Given an array of integers, and the size of that array, return another array of integers that contains the indexes of the elements in the first array that are 'circled' (contain a +1), and also return the size of that second array. (Use the 'return' statement to return the new array, and use a reference parameter to return the array's size.)

	You must make these five subprograms according to their specifications.

	Write the main program to use these subprograms, and others that you want to add, but do not duplicate the code in these functions.

	Each time you create an array, you will need to use dynamic allocation. use pointers to represent the arrays, and direct pointer manipulation to access and traverse the arrays (instead of array indexing).

	One suggestion for a way to get started is to make the functions work with array indexing, then replace all array indexes and index incrementing with pointer dereferencing and direct pointer incrementing before you turn it in. (By the way, ``\*(a + ix)`` is the same as ``a[ix]``, so it is still array indexing).
