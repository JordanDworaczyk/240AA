; Jordan Dworaczyk
; CSC240A
; Program #12A
; Develop some functions to manipulate matrices.

; Given Matrix
(define (Matrix)
  '( ( 2 4 6 8 ) ( 1 3 5 7 ) ( 2 9 0 1 ) )
)

; utility functions

(define (myListLength Lst)
  (if (null? Lst)
    0
    (+ 1 (myListLength (cdr Lst)))
  )
)

(define (myGetElement Lst Pos)
  (if (null? Lst)
    0
    (if (= Pos 1)
      (car Lst)
      (myGetElement (cdr Lst)(- Pos 1))
    )
  )
)

(define (getRow Lst Row)
  (myGetElement Lst Row)
)

(define (getColumn Lst Column)
  (myGetElement Lst Column )
)

(Matrix)


; getCell: Returns the item at the given grid location in a list of lists

(define (getCell Matrix Row Column)
  (getColumn (getRow Matrix Row) Column)
)

(getCell (Matrix) 1 1)
(getCell (Matrix) 1 2)
(getCell (Matrix) 1 3)
(getCell (Matrix) 1 4)
(getCell (Matrix) 2 1)
(getCell (Matrix) 2 2)
(getCell (Matrix) 2 3)
(getCell (Matrix) 2 4)
(getCell (Matrix) 3 1)
(getCell (Matrix) 3 2)
(getCell (Matrix) 3 3)
(getCell (Matrix) 3 4)


; setCell: Returns a new matrix with the given grid location reset to the given
; value 'Item'
