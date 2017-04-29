# Program \#12
Write a Scheme program to play the game _connect 4._

# Rules of the Game
_Connect 4_ is played on a grid of _6 rows_ by _7 columns_. Two players
alternate placing markers on the grid. Each player is assigned a unique shape
or color (like black or red) to distinguish their markers. Each turn consists
of inserting a marker in one of the (unfilled) columns, which causes the next
empty row in that column, starting from the bottom row, to receive that
marker. In other words, each entry adds one more marker to the stack of markers
in the designated column. (No "floating" markers are allowed). Once a column is
full, it may not receive any more markers. The object of the game is to be the
first player to "connect four" adjacent markers of the same shape or color,
either vertically, horizontally, or diagonally.

# User Interface Requirements
To avoid naming clashes between programs, all your functions, plus the one
and only global variable that holds your game state, must be preceded by your
initials: first, middle, and last, as in JEJ for James Earl Jones.

You must provide the following functions for the user (with _XXX_ replaced by
your unique initials):

1. A function to start the game, called `XXXStartGame`, with no arguments, that
returns `#t`.
2. A function to make a move specified by a player, called `XXXMarkMove`, given
one argument that indicates the column (numbered left to right from 1 to 7),
that returns the same column.
3. A function to make a simple graphical display of the current game grid,
called `XXXShowGame`, that receives no arguments and returns `#t`.
4. A function to ask the program to make a move, called `XXXMakeMove`, with no
arguments, that returns the chosen column for the next move.
5. A function, called `XXXLegalmoveP` to test a given move (column) to see if
it's legal with respect to the current game state, and returns true or false
(#t/#f).
6. A function, called `XXXWinP`, to test the current game grid to see if the
last
move resulted in a win; to simplify this task, accept one argument that
represents the column of the latest move, and return true or false.
7. A function, called `XXXWillWInP`, to test the current game grid to see if the
given move (column) will result in a win, and return true or false.

The internal state of your gaming program must be maintained in a global
variable nammed `XXXGame`. All the functions will refer to it to obtain the
currect state of the game. Function  `XXXStartGame` initializes this variable,
and functions `XXXMarkMove` and `XXXShowGame` reset it to reflect the new state
after the move. The other functions do not change this global variable. Notice
that the state of the game must include an indication of which player gets the
next turn as well as the current status of the board (the markers in each
column).

# Implementation Restrictions
You may not use any built-in Scheme functions that we have not discussed. You
may use `begin` for sequence, but only in the `XXXShowGame` function. You may
not use any variables other than the game state variable described above. For
the third function, `XXXMakeMove`, your program may not choose a gaming strategy
that takes an unreasonable amount of time. We will not have an explicit limit,
but if I suspect that someone is not being reasonable, I will disqualify them
from the tournament, and this you will not get full credit for the assignment.

# Structure of functions for Program \#12
``` Lisp
(define (XXXStartGame)
  (begin
    (set! XXXGame ... )
    (display " ... a custom rowsing huzzah for your AI ... \n")
    #t ; to return nothing useful to your opponent
  )
)

(define (XXXMarkMove Col)
  (begin
    (set! XXXGame
      ... ; refer to the old XXXGame
      ... ; do NOT use set! again - no other variables   
    )
    Col
  )
)
; you may NOT use set! anywehre else in the code for this assignment
(define (XXXShowGame)
  (begin
    (display ...) (newline) ; refer to XXXGame
    (display ...) (newline) ; you should be able to use recursion
    #t ; to return something small and not disruptive to the display
  )
)
(define (XXXMakeMove)
  (XXXMarkMove
    (XXXChooseMove ...) ; refer to XXXGame
  )
)
; to generate a random number from 0 to 'N' - 1 (inclusive)
; (random 'N')
```
