; Jordan Dworaczyk
; CSC240A
; Program #12A
; Develop some functions to manipulate matrices.

; Given Matrix
(define (Matrix)
  '( ( 2 4 6 8 ) ( 1 3 5 7 ) ( 2 9 0 1 ) )
)

; utility functions

(define (myAbsolute value)
  (if (< value 0)
    (* value -1)
    value
  )
)

(define (myListLength Lst)
  (if (null? Lst)
    0
    (+ 1 (myListLength (cdr Lst)))
  )
)

(define (myGetElement Lst Pos)
  (if (null? Lst)
    ()
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

(define (myFindElement Lst Pos)
  (if (null? Lst)
    ()
    (if (= Pos 1)
      Lst
      (myFindElement (cdr Lst)(- Pos 1))
    )
  )
)

(define (myFindRow Lst Row)
  (myFindElement Lst Row)
)

(define (myFindColumn Lst Column)
  (myFindElement Lst Column )
)

; insert at given position (assuming positions start at 1)

(define (myInsertAtPos Lst Item Pos)
  (if (= Pos 1)
    (cons Item Lst)
    (if (null? Lst)
      ()
      (cons (car Lst) (myInsertAtPos (cdr Lst) Item (- Pos 1)))
    )
  )
)

; delete the front
(define (myDeleteFront Lst)
  (cdr Lst)
)

; delete the end
(define (myDeleteEnd Lst)
  (if (null? Lst)
    ()
    (myDeleteEndX Lst)
  )
)

; delete the end (assuming non-empty list)
(define (myDeleteEndX Lst)
  (if (null? (cdr Lst))
    ()
    (cons (car Lst) (myDeleteEndX (cdr Lst)))
  )
)

; delete end x times
(define (deleteEndXTimes lst x times)
  (if (= x times)
    lst
    (deleteEndXTimes (myDeleteEnd lst) x (+ times 1))
  )
)
(Matrix)


; getCell: Returns the item at the given grid location in a list of lists

(define (getCell Matrix Row Column)
  (getColumn (getRow Matrix Row) Column)
)

(define (firstPart lst Row Column)
  (deleteEndXTimes (getRow lst Row) (- (myListLength
    (getRow lst Row)) (- Column 1)) 0)
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

(define (middle Lst Row Column Item)
  (myInsertAtPos
    (myFindElement
      (myInsertAtPos
        (getRow Lst Row)
        Item
        (+ Column 1)
      )
      (+ 1 Column)
    )
    (firstPart Lst Row Column)
    1
  )
)

(define (combine lstA lstB)
  (if (null? (cdr lstA))
    (cons
      (car lstA)
      lstB
    )
    (cons
      (car lstA)
      (combine (cdr lstA) lstB)
    )
  )
)

(define (insertLittle Matrix Row Column Item)
  (if (null? Matrix)
    ()
    (if (= 1 Column)
      (myInsertAtPos
        (cdr (getRow Matrix Row))
        Item
        Column
      )
      (if (= Column (myListLength (getRow Matrix Row)))
        (myDeleteEnd
          (myInsertAtPos
            (getRow Matrix Row)
            Item
            Column
          )
        )
        (combine
          (firstPart Matrix Row Column)
          (cdr (middle Matrix Row Column Item))
        )
      )
    )
  )

)

(define (setCell Matrix Row Column Item )
  (if (= 1 Column)
    (myInsertAtPos
      (cdr Matrix)
      (insertLittle Matrix Row Column Item)
      Row
    )
    (if (= Column (myListLength Matrix))
      (myDeleteEnd
        (myInsertAtPos
          (getRow Matrix Row)
          (insertLittle Matrix Row Column Item)
          Column
        )
      )
      (combine
        (firstPart Matrix Row Column)
        (cdr (middle Matrix Row Column (insertLittle Matrix Row Column Item)))
      )
    )
  )
)


(setCell (Matrix) 1 1 10)
(setCell (Matrix) 1 2 10)
(setCell (Matrix) 1 3 10)
(setCell (Matrix) 1 4 10)
(setCell (Matrix) 2 1 10)
(setCell (Matrix) 2 2 10)
(setCell (Matrix) 2 3 10)
(setCell (Matrix) 2 4 10)
(setCell (Matrix) 3 1 10)
(setCell (Matrix) 3 2 10)
(setCell (Matrix) 3 3 10)
(setCell (Matrix) 3 4 10)
