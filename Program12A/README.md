# Program#12 Phase I (Program#12A)
---


### Assignment  
Develop some functions to manipulate matrices.

### Implementation  

 A _"matrix"_ is a two-dimensional grid.  

###### For example:  
```
2 9 0 1  
1 3 5 7  
2 4 6 8  
```
This is a matrix of 3 rows (horizontal) by 4 columns (vertical), or 3x4 matrix.
A matrix can be represented in Lisp as a list of lists, with each list
representing one row.  

###### For example:
`'( ( 2 4 6 8 ) ( 1 3 5 7 ) ( 2 9 0 1 ) )`

For convenience with a later assignment, we will number the rows from bottom to
top, and the columns from left to right. For instance, the number _8_ is at row
1 and column 4, and the item at row 3 column 2 is _9_.

###### Terms

In each of the following descriptions,  
*  _'Item'_ is an arbritary item (numbers or symbols).
*  _'Matrix'_ is a list of one or more lists of items (described above).
*  _'Column'_ is a column number in the matrix, from one to the number of columns.
*  _'Row'_ is a row number in the matrix, from one to the number of rows.

---

### Requirements
Provide one Lisp function for each of the following:  
1. `(getCell Matrix Row Column )`  
  * Returns the item at the given grid location in a list of lists.
2. `(setCell Matrix Row Column Item )`  
  * Returns a new matrix with the given grid location reset to the given value
  _'Item'_

###### Assumptions
* Assume that the given _'Row'_ and _'Column'_ are always valid.
* Assume that any list parameter is a list (and
  **NOT** an atom).
* Assume that any given item is not nil.

###### Note
Use only the Scheme functions that we have discussed in class. Do *NOT* use
variables (except for the parameters). Define the functions recursively rather
than using iteration. Remember to handle the empty list, and positions outside
the valid range. Notice that the position of the first row or column in the
list is 1 (not 0 as it is in Java and C++ arrays).  
