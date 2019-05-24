#lang racket

(define make-queue
  (lambda ()
    (cons '() '())))

(define enqueue!
  (lambda (queue obj)
    (let ((lobj (cons obj '())))
      (if (null? (car queue))
          (begin
            (set-car! queue lobj)
            (set-cdr! queue lobj))
          (begin
            (set-cdr! (cdr queue) lobj)
            (set-cdr! queue lobj)))
      (car queue))))

(define dequeue!
  (lambda (queue)
    (let ((obj (car (car queue))))
      (set-car queue (cdr (car queue)))
      obj)))