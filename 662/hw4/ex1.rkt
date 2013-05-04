#lang plai
(require racket/trace)

;;; Define an AST type for CFWAE/S constructs.
(define-type CFWAE/S
  (num (n number?))
  (add (lhs CFWAE/S?) (rhs CFWAE/S?))
  (sub (lhs CFWAE/S?) (rhs CFWAE/S?))
  (mul (lhs CFWAE/S?) (rhs CFWAE/S?))
  (div (lhs CFWAE/S?) (rhs CFWAE/S?))
  (id (name symbol?))
  (with (name symbol?) (named-expr CFWAE/S?) (body CFWAE/S?))
  (if0 (cond CFWAE/S?) (tarm CFWAE/S?) (farm CFWAE/S?))
  (fun (arg-name symbol?) (body CFWAE/S?))
  (app (fun-expr CFWAE/S?)(arg CFWAE/S?))
  (seq (expr-one CFWAE/S?) (expr-two CFWAE/S?))
  (assign (id symbol?)(expr CFWAE/S?)))

(define-type Env
  (mtSub)
  (aSub (name symbol?)
        (location number?)
        (env Env?)))

(define-type Store
  (mtStore)
  (aStore (location number?)
          (value CFWAE/S-Value?)
          (store Store?)))
          
(define-type ValueXStore
  (vxs (value CFWAE/S-Value?)
       (store Store?)))

(define-type CFWAE/S-Value
  (numV (n number?))
  (closureV (param symbol?)
            (body CFWAE/S?)
            (env Env?)))
  
(define (boxed-CFWAE/S-Value? v)
  (and (box? v)
       (CFWAE/S-Value? (unbox v))))

(define (env-lookup name env)
  (type-case Env env
    (mtSub ()(error "env-lookup: No binding for identifier"))
    (aSub (bound-name bound-location rest-env)
          (if (symbol=? bound-name name)
              bound-location
              (env-lookup name rest-env)))))
;(trace env-lookup)

(define (store-lookup location store)
  (type-case Store store
    (mtStore ()(error "store-lookup: failed to find identifier"))
    (aStore (bound-location value rest-store)
            (if(= bound-location location)
               value
               (store-lookup location rest-store)))))
(trace store-lookup)

(define new-location
  (local ((define loc (box 0)))
    (lambda ()
      (begin (set-box! loc (+ 1 (unbox loc)))
             (unbox loc)))))
  
        

(define (interp expr env store)
  (type-case CFWAE/S expr
    (num (n)(vxs (numV n) store))
    (id (v)(vxs (store-lookup (env-lookup v env) store) store))
    (add (l r)
         (type-case ValueXStore (interp l env store)
           (vxs (l-value l-store)
                (type-case ValueXStore (interp r env l-store)
                  (vxs (r-value r-store)
                       (vxs (numV (+ (numV-n l-value) (numV-n r-value)))
                            r-store))))))
    (sub (l r)
         (type-case ValueXStore (interp l env store)
           (vxs (l-value l-store)
                (type-case ValueXStore (interp r env l-store)
                  (vxs (r-value r-store)
                       (vxs (numV (- (numV-n l-value) (numV-n r-value)))
                            r-store))))))
    (mul (l r)
         (type-case ValueXStore (interp l env store)
           (vxs (l-value l-store)
                (type-case ValueXStore (interp r env l-store)
                  (vxs (r-value r-store)
                       (vxs (numV (* (numV-n l-value) (numV-n r-value))) 
                            r-store))))))
    (div (l r)
         (type-case ValueXStore (interp l env store)
           (vxs (l-value l-store)
                (type-case ValueXStore (interp r env l-store)
                  (vxs (r-value r-store)
                       (vxs (numV (/ (numV-n l-value) (numV-n r-value))) 
                            r-store))))))
    (fun (bound-id bound-body)
         (vxs (closureV bound-id bound-body env) store))
    (if0 (c t e)
         (type-case ValueXStore (interp c env store)
           (vxs (c-value c-store)
                (if(eq? c-value 0)
                   (interp t env c-store)
                   (interp e env c-store)))))
    (with (id n-e b) ;; Elab with into an app expression
          (interp (app (fun id b) n-e) env store))
    (app (fun-expr arg-expr)
         (type-case ValueXStore (interp fun-expr env store)
           (vxs (fun-value fun-store)
                (type-case ValueXStore (interp arg-expr env fun-store)
                  (vxs (arg-value arg-store)
                       (local ((define new-loc (new-location)))
                         (interp (closureV-body fun-value)
                                 (aSub (closureV-param fun-value)
                                       new-loc
                                       (closureV-env fun-value))
                                 (aStore new-loc
                                         arg-value
                                         arg-store))))))))
    (seq (expr1 expr2) 
         (type-case ValueXStore (interp expr1 env store)
           (vxs (1-value 1-store)
                (interp expr2 env 1-store))))
    (assign (id bound-expr)
            (type-case ValueXStore (interp bound-expr env store)
              (vxs (bound-value bound-store)
                   (let ((id-loc (env-lookup id env)))  
                     (vxs bound-value
                          (aStore id-loc
                                  bound-value
                                  bound-store))))))))
;(trace interp)
                     
 
(define parse-CFWAE/S
  (lambda (expr)
    (cond ((symbol? expr) (id expr))
          ((number? expr) (num expr))
          ((list? expr)
           (case (car expr)
             ((-) (sub (parse-CFWAE/S (cadr expr)) (parse-CFWAE/S (caddr expr))))
             ((+) (add (parse-CFWAE/S (cadr expr)) (parse-CFWAE/S (caddr expr))))
             ((*) (mul (parse-CFWAE/S (cadr expr)) (parse-CFWAE/S (caddr expr))))
             ((/) (div (parse-CFWAE/S (cadr expr)) (parse-CFWAE/S (caddr expr))))
             ((seq) (seq (parse-CFWAE/S (cadr expr)) 
                         (parse-CFWAE/S (caddr expr))))
             ((assign) (assign (cadr expr)
                               (parse-CFWAE/S (caddr expr))))
             ((with) (with (car (cadr expr)) 
                            (parse-CFWAE/S (cadr (cadr expr))) 
                            (parse-CFWAE/S (caddr expr))))
             ((if0) (if0 (parse-CFWAE/S (cadr expr)) (parse-CFWAE/S (caddr expr))
                         (parse-CFWAE/S (cadddr expr))))
             ((fun) (fun (caadr expr) (parse-CFWAE/S (caddr expr))))
             (else (app (parse-CFWAE/S (car expr)) (parse-CFWAE/S (cadr expr))))))
          (else 'parse-CFWAE/S "Unexpected token"))))

(define test2
  '(with (f 3)(seq (assign f 4)(* f 5))))

(define (eval-CFWAE/S expr)
  (interp (parse-CFWAE/S expr)(mtSub)(mtStore)))

(define (test-parse expr)
  (parse-CFWAE/S expr))

(eval-CFWAE/S test2)






