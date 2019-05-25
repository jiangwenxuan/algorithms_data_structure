#lang racket

(define make-queue
  (lambda ()
    (list 'queue (cons '() '()))))

(define queue
  (lambda (q)
    (if (queue? q)
        (list-ref q 1)
        (error "q is not queue."))))

(define queue?
  (lambda (q)
    (cond
      ((null? q) #f)
      ((not (pair? q)) #f)
      (else (eq? 'queue (list-ref q 0))))))

(define queue-head
  (lambda (q)
    (cond
      ((not (queue? q)) (error "q is not queue."))
      ((queue-empty? q) (error "q is empty queue."))
      (else (car (queue q))))))

(define queue-tail
  (lambda (q)
    (cond
      ((not (queue? q)) (error "q is not queue."))
      ((queue-empty? q) (error "q is empty queue."))
      (else (cdr (queue q))))))

(define queue-empty?
  (lambda (q)
    (null? (car (queue q)))))

(define queue-enqueue!
  (lambda (q obj)
    (let ((lobj (cons obj '())))
      (if (queue-empty? q)
          (begin
            (set-car! (queue q) lobj)
            (set-cdr! (queue q) lobj))
          (begin
            (set-cdr! (queue-tail q) lobj)
            (set-cdr! (queue q) lobj)))
      q)))

(define queue-dequeue!
  (lambda (q)
    (let ((obj (queue-head q)))
      (set-car! (queue q) (cdr obj))
      (car obj))))

(define (queue->list q)
  (car (queue q)))