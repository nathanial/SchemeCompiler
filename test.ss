(define (add x y)
  (+ x y))

(define (sub x y)
  (- x y))

(define (choose x)
  (cond 
   ((< x 0) 1)
   ((> x 0) 2)
   ((else 0))))