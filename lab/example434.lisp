;;
;;  Grammar 4.34 (page 222 (4.19))
;;

(defpackage #:example434
  (:export #:example434)
  (:use #:cl #:yacc))

(in-package #:example434)

;;;
;;; The parser
;;;
(eval-when (:compile-toplevel :load-toplevel :execute)
  (defun add_them ($1 $2 $3)
    (declare (ignore $2))
    (+ $1 $3))

  (defun multiply_them ($1 $2 $3)
    (declare (ignore $2))
    (* $1 $3))

  (defun k-2-3 ($1 $2 $3)
    (declare (ignore $1 $3))
    $2)
)

(define-parser *yyparse*
  (:start-symbol S)
  (:terminals (id +  * |(| |)|))
  (:precedence ((:left * ) (:left + )))

  (S
   E                           ; implicit action #'identity
   ())

  (E
   (E + T #'add_them)
   T)                          ; implicit action #'identity

  (T
   (T * F #'multiply_them)
    F)

  (F
   id                          ; implicit action #'identity
   (|(| E |)| #'k-2-3)))

;;;
;;; The lexer
;;;
(define-condition lexer-error (yacc-runtime-error)
  ((character :initarg :character :reader lexer-error-character))
  (:report (lambda (e stream)
             (format stream "Lexing failed~@[: unexpected character ~S~]"
                     (lexer-error-character e)))))

(defun lexer-error (char)
  (error (make-condition 'lexer-error :character char)))

(defun maybe-unread (char stream)
  (when char
    (unread-char char stream)))

(defun read-number (stream)
  (let ((v nil))
    (loop
       (let ((c (read-char stream nil nil)))
         (when (or (null c) (not (digit-char-p c)))
           (maybe-unread c stream)
           (when (null v)
             (lexer-error c))
           (return-from read-number v))
         (setf v (+ (* (or v 0) 10) (- (char-code c) (char-code #\0))))))))

(defun lexer (&optional (stream *standard-input*))
  (loop
     (let ((c (read-char stream nil nil)))
       (cond
         ((member c '(#\Space #\Tab)))
         ((member c '(nil #\Newline)) (return-from lexer (values nil nil)))
         ((member c '(#\+ #\* #\( #\)))
          (let ((symbol (intern (string c) '#.*package*)))
            (return-from lexer (values symbol symbol))))
         ((digit-char-p c)
          (unread-char c stream)
          (return-from lexer (values 'id (read-number stream))))
         (t
          (lexer-error c))))))

;;;
;;; The toplevel loop
;;;
(defun example434 ()
  (format t "Type an infix expression to evaluate it, an empty line to quit.~%")
  (loop
     (with-simple-restart (abort "Return to example434 toplevel.")
       (format t "? ")
       (let ((e (parse-with-lexer #'lexer *yyparse*)))
         (when (null e)
           (return-from example434))
         (format t " => ~A~%" e)))))
