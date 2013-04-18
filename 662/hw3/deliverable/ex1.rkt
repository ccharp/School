#lang plai

;;; Define an AST type for CFWAER constructs.
(define-type CFWAER
  (num (n number?))
  (add (lhs CFWAER?) (rhs CFWAER?))
  (sub (lhs CFWAER?) (rhs CFWAER?))
  (mul (lhs CFWAER?) (rhs CFWAER?))
  (div (lhs CFWAER?) (rhs CFWAER?))
  (id (name symbol?))
  (with (name symbol?) (named-expr CFWAER?) (body CFWAER?))
  ;(rec (name symbol?) (named-expr CFWAER?) (body CFWAER?))
  (if0 (cond CFWAER?) (tarm CFWAER?) (farm CFWAER?))
  (fun (arg-name symbol?) (body CFWAER?))
  (app (fun-expr CFWAER?)(arg CFWAER?)))

(define-type CFWAER-Value
  (numV (n number?))
  (closureV (param symbol?)
            (body CFWAER?)
            (ds DefrdSub?)))

(define-type DefrdSub
  (mtSub)
  (aSub (name symbol?)(value CFWAER-Value?)(ds DefrdSub?)))

(define (lookup name ds)
  (type-case DefrdSub ds
    (mtSub ()(error "no biding name for indentifier"))
    (aSub (bound-name bound-value rest-ds)
          (if (symbol=? bound-name name)
              bound-value
              (lookup name rest-ds)))))

(define (interp expr ds)
  (type-case CFWAER expr
    (num (n)(numV n))
    (add (l r)(numV (+ (numV-n (interp l ds))(numV-n (interp r ds)))))
    (sub (l r)(numV (- (numV-n (interp l ds))(numV-n (interp r ds)))))
    (mul (l r)(numV (* (numV-n (interp l ds))(numV-n (interp r ds)))))
    (div (l r)(numV (/ (numV-n (interp l ds))(numV-n (interp r ds)))))
    (id (v)(lookup v ds))
    (fun (bound-id bound-body)
         (closureV bound-id bound-body ds))
    (with (id n-e b) ;; inline elab to app
          (interp (app (fun id b) n-e) ds))
    (if0 (c t e)(if (eq? (num-n (interp c ds))0)
                      (interp t ds)
                      (interp e ds)))
    (app (fun-expr arg-expr)
         (local ((define fun-val (interp fun-expr ds)))
           (interp (closureV-body fun-val)
                   (aSub (closureV-param fun-val)
                         (interp arg-expr ds)
                         (closureV-ds fun-val)))))))
    
;;; Define a parser for CFWAER constructs.  This parser does no error checking at all. Simply converts
;;; concrete syntax to AST.
(define parse-cfwaer
  (lambda (expr)
    (cond ((symbol? expr) (id expr))
          ((number? expr) (num expr))
          ((list? expr)
           (case (car expr)
             ((-) (sub (parse-cfwaer (cadr expr)) (parse-cfwaer (caddr expr))))
             ((+) (add (parse-cfwaer (cadr expr)) (parse-cfwaer (caddr expr))))
             ((*) (mul (parse-cfwaer (cadr expr)) (parse-cfwaer (caddr expr))))
             ((/) (div (parse-cfwaer (cadr expr)) (parse-cfwaer (caddr expr))))
             ((with) (with (car (cadr expr)) 
                            (parse-cfwaer (cadr (cadr expr))) 
                            (parse-cfwaer (caddr expr))))
             ;((rec) (rec (car (cadr expr)) 
              ;              (parse-cfwaer (cadr (cadr expr))) 
               ;             (parse-cfwaer (caddr expr))))
             ((if0) (if0 (parse-cfwaer (cadr expr)) (parse-cfwaer (caddr expr))
                         (parse-cfwaer (cadddr expr))))
             ((fun) (fun (caadr expr) (parse-cfwaer (caddr expr))))
             (else (app (parse-cfwaer (car expr)) (parse-cfwaer (cadr expr))))))
          (else 'parse-cfwaer "Unexpected token"))))

;;; Factorial example from class.  Try (parse-cfwaer fac5) to see the parser produce an AST
;;; for the example.

(define fac5
  '{rec {fac {fun {n} {if0 n 1 {* n {fac {+ n -1}}}}}}{fac 5}}
  )

(define (eval-cfwaer expr)
  (interp (parse-cfwaer expr) (mtSub)))