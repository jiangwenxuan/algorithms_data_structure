#lang racket

(define make-stack
  (lambda ()
    (list 'stack)))

(define stack?
  (lambda (s)
    (cond
      ((null? s) #f)
      ((not (pair? s)) #f)
      (else (equal? 'stack (car s))))))

(define stack
  (lambda (s)
    (if (stack? s)
        (cdr s)
        (error "not a stack"))))

(define stack-size
  (lambda (s)
    (length (cdr s0))))

(define stack-empty?
  (lambda (s)
    (null? (stack s))))

(define stack-print
  (lambda (s)
    (display (reverse (stack s)))))

(define stack-member
  (lambda (s e)
    (member e (stack s))))

(define stack-top
  (lambda (s)
    (if (stack-empty? s)
        (error "stack is empty")
        (car (stack s)))))

(define stack-pop!
  (lambda (s)
    (if (stack-empty? s)
        (error "cannot pop element from a empty stack")
        (let ((ret (car (stack s))))
          (begin
            (set-cdr! s (cdr (stack s)))
            ret)))))

(define stack-reverse!
  (lambda (s)
    (set-cdr! s (reverse (stack s)))))

(define list->stack
  (lambda (l)
    (cons 'stack (reverse l))))

(define stack->list
  (lambda (s)
    (reverse (stack s))))