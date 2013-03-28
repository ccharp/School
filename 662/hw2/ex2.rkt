#lang plai

(require racket/trace)

(define-type CFAE
  (id (name symbol?))
  (num (n number?))
  (plus (lhs CFAE?)(rhs CFAE?))
  (minus (lhs CFAE?)(rhs CFAE?))
  (mult (lhs CFAE?)(rhs CFAE?))
  (divide (lhs CFAE?)(rhs CFAE?))
  (fun (param symbol?)(body CFAE?))
  (app (fun-expr CFAE?)(arg-expr CFAE?))
  (if0 (cond CFAE?)(then CFAE?)(else CFAE?)))

(define-type DefrdSub
  (mtSub)
  (aSub (name symbol?)(value CFAE?)(ds DefrdSub?)))

(define lookup
  (lambda (name ds)
    (type-case DefrdSub ds
      (mtSub () (error "in loop: undefined character"))
      (aSub (bound-name bound-value rest-ds)
            (if (symbol=? name bound-name)
                bound-value
                (lookup name rest-ds))))))
;(trace lookup)

(define interp-cfae
  (lambda (expr ds)
    (type-case CFAE expr
      (id (x)(lookup x ds))
      (num (n)(num n))
      (plus (l r)(num (+ (num-n (interp-cfae l ds))(num-n (interp-cfae r ds)))))
      (minus (l r)(num (- (num-n (interp-cfae l ds))(num-n (interp-cfae r ds)))))
      (mult (l r)(num (* (num-n (interp-cfae l ds))(num-n (interp-cfae r ds)))))
      (divide (l r)(num (/ (num-n (interp-cfae l ds))(num-n (interp-cfae r ds)))))
      (fun (param body)expr)
      (app (fun-expr arg-expr)
           (local ((define fun-val (interp-cfae fun-expr ds)))
                   (interp-cfae (fun-body fun-val)
                           (aSub (fun-param fun-val)(interp-cfae arg-expr ds) ds))))
      (if0 (c t e)(if (eq? (num-n(interp-cfae c ds))0)
                      (interp-cfae t ds)
                      (interp-cfae e ds))))))
 
(define-type CFWAE
  (idW (name symbol?))
  (numW (n number?))
  (plusW (lhs CFWAE?)(rhs CFWAE?))
  (minusW (lhs CFWAE?)(rhs CFWAE?))
  (multW (lhs CFWAE?)(rhs CFWAE?))
  (divideW (lhs CFWAE?)(rhs CFWAE?))
  (funW (param symbol?)(body CFWAE?))
  (appW (fun-name symbol?)(arg-expr CFWAE?))
  (withW (name symbol?)(named-expr CFWAE?)(body CFWAE?))
  (if0W (cond CFWAE?)(then CFWAE?)(else CFWAE?)) 
  (cond0W (loc loc?)))

;we have a list of conditions if the list has an odd length (default case)
(define loc?
  (lambda (conds)
    (and (>= (length conds) 3)
         (eq? (modulo (length conds) 2) 1)
         (andmap CFWAE? conds))))

(define buildIfs
  (lambda (conds)
    (if (eq? (length conds) 1)
        (elab-cfwae (car conds))
        (if0 (elab-cfwae (car conds))
             (elab-cfwae (second conds))
             (buildIfs (cddr conds))))))

(define elab-cfwae
  (lambda (expr)
    (type-case CFWAE expr
      (numW (n)(num n))
      (idW (x)(id x))
      (plusW (l r) (plus (elab-cfwae l)(elab-cfwae r)))
      (minusW (l r) (minus (elab-cfwae l)(elab-cfwae r)))
      (multW (l r) (mult (elab-cfwae l)(elab-cfwae r)))
      (divideW (l r)(divide (elab-cfwae l)(elab-cfwae r)))
      (funW (param body)(fun param (elab-cfwae body)))
      (appW (fun-expr arg-expr)(app (id fun-expr)(elab-cfwae arg-expr)))
      (if0W (c t e)(if0 (elab-cfwae c)(elab-cfwae t)(elab-cfwae e)))
      (withW (id n-e b)(app (fun id (elab-cfwae b))(elab-cfwae n-e)))
      (cond0W (conds)(buildIfs conds)))))

(define prelude 
  (aSub 'area (fun 'x (mult (id 'pi)(id 'x))) 
        (aSub 'inc (fun 'x (plus (id 'x)(num 1))) 
              (aSub 'pi (num 3.1415) (mtSub)))))
                
(define eval-cfwae   
  (lambda (expr)
    (interp-cfae 
     (elab-cfwae expr)
     prelude)))
      
      

(test (eval-cfwae (cond0W (list (numW 1) (numW 2) (numW 0) (numW 15) (numW 0)))) (num 15))
(test (eval-cfwae (withW 'x (numW 10) (plusW (idW 'x) (numW 5)))) (num 15))
(test (eval-cfwae (withW 'add1 (funW 'x (plusW (idW 'x) (numW 1)))
                      (cond0W (list (appW 'add1 (numW 0)) (numW 5)
                                    (numW 3) (numW 4)
                                    (numW 0) (appW 'add1 (numW 2))
                                    (numW 2)))))
      (num 3))

      
              
                           
