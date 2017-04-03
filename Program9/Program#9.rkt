; Jordan Dworaczyk
; CSC240AA
; Program #9 (Scheme)
; Due 4/3
; Develop a library of Scheme functions to manipulate a 'Bag of Strings'. Store
; each bag as a list of ordered pairs where the first element of each pair is
; the value and the second element is its frequency.


(define Bag '( ( "a" . 3 ) ( "b" . 1 ) ( "c" . 2 ) ( "a" . 3) ) )

(define (firstPair)
  (car Bag)
)

(define (secondPair)
  (car (cdr Bag))
)

(define (thirdPair)
  (car (cdr (cdr Bag)))
)

(define (fourthPair)
  (car (cdr (cdr (cdr Bag))))
)

; (1) return the String value of the pair
(define (getValue Pair)
  (car Pair)
)

; (2) return the integer frequency of the pair
(define (getCount Pair)
  (cdr Pair)
)

; (3) create a new pair representing one of the given items
(define (newPair Item)
  (cons Item  1 )
)

; (4) return a new pair that represents one more of the items
(define (incPair Pair)
  (cons
    (getValue Pair)
    (+ (getCount Pair) 1 )
  )
)

; (5) return a new pair that represents one less of the items
(define (decPair Pair)
  (cons
    (getValue Pair)
    (- (getCount Pair) 1 )
  )
)

; (6) return a new bag that represents the result of inserting the given item
; in the given list
(define (insertBag List Item)
  (if (null? List)
    (cons Item () )
    (cons (car List) (insertBag (cdr List) Item) )
  )
)

; (7) return the number of times the given item is in the given list
(define (getBagCount List Item)
  (if (null? List)
    0
    (if (string=? (getValue (car List)) Item)
      (+ 1 (getBagCount (cdr List) Item) )
      ( + 0 (getBagCount (cdr List) Item ) )
    )
  )
)

; (8) return a new bag that represents the result of deleting one occurrence of
; the given item form the given list
(define (deleteBag List Item)
  (if (null? List)
    ()
    (if (string=? (getValue (car List)) Item)
      (cdr List)
      (cons (car List) (deleteBag (cdr List) Item) )
    )
  )
)

; (9) return a new bag that represents the result of deleting all occurrences
; of the given item in the list
(define (deleteAllBag List Item)
  (if (null? List)
    List
    (if (string=? (getValue (car List)) Item)
      (deleteAllBag (cdr List) Item )
      (cons (car List) (deleteAllBag (cdr List) Item ) )
    )
  )
)

; (10) return a new bag that represents the result of the union of the two given
; bags (combine the contents of both - take the sum of the frequencies of each
; element in the two bags)
(define (unionBag ListA ListB)
  (if (null? ListA)
    ()
    (if (null? ListB)
      ()
      (if (string=?
            (getValue (car ListA))
            (getValue (car ListB))
          )
        (if (< (getBagCount ListA (getValue (car ListA))) 2)
          (cons
            (cons
              (getValue (car ListA))
              (+
                (getCount (car ListA))
                (getCount (car ListB))
              )
            )
            (unionBag (cdr ListA) (cdr ListB))
          )
          (unionBag ListB ListA)
        )
        (cons
          (car ListA)
          (unionBag (ListA) (cdr ListB))
        )
      )
    )
  )
)


(define Bag2 '( ( "a" . 2 ) ( "b" . 1 )  ( "c" . 2 ) ) )
