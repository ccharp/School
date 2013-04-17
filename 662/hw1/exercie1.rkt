#lang plai

(require racket/trace)

(define-type WAE
  (num (n number?))
  (add (lhs WAE?)(rhs WAE?))
  (sub (lhs WAE?)(rhs WAE?))
  (with (name symbol?)(named-expr WAE?)(body WAE?))
  (id (name symbol?)))

(define parse
  (lambda (sexp)
    (cond((number? sexp)(num sexp))
         ((symbol? sexp)(id sexp))
         ((list? sexp)
            (case (car sexp)
              ('+ (add (parse (cadr sexp))
                       (parse (caddr sexp))))
              ('- (sub (parse (cadr sexp))
                       (parse (caddr sexp))))
              ('with (with (caadr sexp) ;name
                           (parse (cadadr sexp)) ;named-expr
                           (parse (caddr sexp))))))))) ;body

(define eval
  (lambda (a-wae)
    (type-case WAE a-wae
      (num (n) n)
      (add (l r)(+ (eval l)(eval r)))
      (sub (l r)(- (eval l)(eval r)))
      (with (name bound-value body)
            (eval (subst name bound-value body)))
      (id (i) (error "you dun screwed up"))
      )
    )
  )

(define subst
  (lambda (sub-id value expr)
    (type-case WAE expr
      (num (n) expr)
      (id (i)(if(symbol=? i sub-id)
          value
          expr))
      (add (l r)
           (add (subst sub-id value l)
                (subst sub-id value r)))
      (sub (l r)
           (sub (subst sub-id value l)
                (subst sub-id value r)))
      (with (bound-id named-expr bound-body)
            (if(symbol=? bound-id sub-id)
               expr
               (with bound-id named-expr
                     (subst sub-id value bound-body)
                     )
               )
            )
      )
    )
  )

(define eval-wae
  (lambda (wae)
    (eval (parse wae))))
  
(define test-case '(with (x (- 6 1))(+(with (x 22)(+ x x)) x)))

(define test-subst0
  (lambda ()
    (subst 'x 7 (id 'x))))

(define test-subst1
  (lambda ()
    (subst 'x 7 (add (sub (id 'x)(num 3)) (id 'x)) ) ))

(define test-subst2
  (lambda ()
    (subst 'x 7 (with 'y (num 7)
                      (with 'z (num 8)
                           (sub (id 'x)(id 'x)))))))     
  
(define test-subst3
  (lambda ()
    (subst 'x 7 (with 'y (id 'x)
                      (with 'z (num 8)
                           (sub (id 'y)(id 'y)))))))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;PART 2;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
















































   