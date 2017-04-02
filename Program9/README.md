Develop a library of Scheme functions to manipulate a _Bag of Strings_. Store
each bag as a list of ordered pairs where the first element of each pair is the
value and the second element is its frequency.

For example, the bag (a, a, a, b, c, c) will be stored as follows:
> ( ( a , 3 ) , ( b , 1 ) , ( c , 2 ) )

Recall that a _"set"_ is a collection of unique, unordered objects: 'unique'
because the set may not contain any duplicates. In contrast, a _"bag"_ is a
collection of unordered objects that may contain duplicate entries.

### Implementation
Implement each pair in Scheme fashion as a _"dotted-pair"_ (with the `car` holding the String value and the `cdr` holding the integer frequency).
Implement the Bag as a Scheme list of these pairs (with the `car` holding a
reference to a pair and the `cdr` holding a reference to the rest of the list).

Therefore, the bag above would be represented as:
> ``( ( "a" . 3 ) ( "b" . 1 ) ( "c" . 2 ) )`

In each of the following descriptions:
> * 'List' is a list of zero or more ordered pairs.
* 'Pair' is an ordered pair as described above (value and frequency).
* 'Item' is a String (surrounded by double-quotes).

Provide one Scheme functions for each of the following:
> 1. `(getValue Pair)` -- return the String value of the pair
2. `(getCount Pair)` -- return the integer frequency of the pair
3. `(newPair Item)` -- create a new pair representing one of the given items
4. `(incPair Pair)` -- return a new pair that represents one **more** of the
items
5. `(decPair Pair)` -- return a new pair that represents one **less** of the
items
6. `(insertBag List Item)` -- return a new bag that represents the result of
inserting the given item in the given list
7. `(getBagCount List Item)` -- return the number of ties the given item is
in the given list
8. `(deleteBag List Item)` -- return a new bag that represents the result of
deleting all occurrences of the given item from the given list
9. `(deleteAllBag List Item)` -- return a new bag that represents the result
of the union of the two given bags (combine the contents of both - take the
sum of the frequencies of each element in the two bags)
10. `(unionBag ListA ListB)` -- return a new bag that represents the result of
the union of the two given bags (combine the contents of both - take the sum of
the frequencies of each element in the two bags)
11. `(intersectBag ListA ListB)` -- return a new bag that represents the
result f the intersection of the two given bags (take the minimum frequency of
each element in the two bags)

#### Note:
Use only the Scheme functions that we have discussed in class. Do **NOT** use
variables (except for the parameters). Define the functions recursively rather
than using iteration. Handle the empty bag. Assume that any list parameter is a
valid list of pairs (and **NOT** an atom). Assume that an item parameter is a
valid string. Use the `string=?` predicate to test for equal strings. Maintain
the pairs so that the _'frequency'_ or _'count'_ is always a positive number.
