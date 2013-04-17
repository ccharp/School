#lang plai

(require racket/trace)

(define-type Binop
  (binop (name symbol?) (op procedure?))) ;map symbol to function

(define-type WAEE
  (num (n number?))
  (oper (bin Binop?)(lhs WAEE?)(rhs WAEE?))
  (with (lob lob?)(body WAEE?))
  (id (name symbol?)))

(define binding?
  (lambda (x)
    (and (symbol? (first x))(WAEE? (second x)))))

(define lob?
  (lambda (x)
    (cond ((empty? x) #t)
          (else (and (binding? (car x))(lob? (cdr x)))))))

(define extract-named-expr
  (lambda (bindings)
    (map (lambda (pair)
           (list (car pair)(parse (cadr pair))))
         bindings))) 

(define parse
  (lambda (sexp)
    (cond((number? sexp)(num sexp))
         ((symbol? sexp)(id sexp))
         ((list? sexp)
            (case (car sexp)
              ('+ (oper (binop '+ +) 
                        (parse (cadr sexp))
                        (parse (caddr sexp))))
              ('- (oper (binop '- -) 
                        (parse (cadr sexp))
                        (parse (caddr sexp))))
              ('* (oper (binop '* *) 
                        (parse (cadr sexp))
                        (parse (caddr sexp))))
              ('/ (oper (binop '/ /) 
                        (parse (cadr sexp))
                        (parse (caddr sexp))))
              ('with (with (extract-named-expr (cadr sexp))
                           (parse (caddr sexp)))))))))


(define interp-waee
  (lambda (a-waee)
    (type-case WAEE a-waee
      (num (n) n)
      (oper (operation l r)(type-case Binop operation ;is there a better way to do this unboxing without a typecase?
                             (binop (n f) (f (interp-waee l)(interp-waee r)))))
      (with (bindings body)
            (interp-waee (subst bindings body)))
      (id (i) (error "you dun screwed up, or maybe I did"))
      )
    )
  )


(define get-bindings-expr?
  (lambda (symbol bindings)
    (cond ((empty? bindings) #f)
          ((symbol=? symbol (caar bindings))(cadar bindings))
          (else (get-bindings-expr? symbol (cdr bindings))))))

(define subst
  (lambda (sub-ids expr)
    (type-case WAEE expr
      (num (n) expr)
      (id (i)(if(get-bindings-expr? i sub-ids) ;in hindsight, I should have stored these in a hash 
          (get-bindings-expr? i sub-ids)       ; insead of lists
          expr))
      (oper (f-obj l r)
           (oper f-obj
                 (subst sub-ids l)
                 (subst sub-ids r)))
      (with (bindings body)
            (let ((uncommon-bindings (filter
                                      (lambda(x)
                                        (not(member (car x) (map car bindings)))) 
                                      sub-ids)))
              (if(empty? uncommon-bindings)
                 expr
                 (with bindings
                       (subst uncommon-bindings body))))))))
(trace subst)


(define eval-waee
  (lambda (wae)
    (interp-waee (parse wae))))

(define test-case1 '(with ((x (+ 1 2)))(+ x 5)))
(define test-case2 '(with ((x 12)(y 2))(+ x (with ((x 15))(+ x y)))))
(define test-case3 '(+ 3 (with ((x 12)(y (with ((z 4))(/ 4 1))))(+ x (with ((x 15))(+ x x))))))

