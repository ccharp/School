


dropThird i (x:xs)
    | null xs = []
    | i - 3 == 0 = dropThird 1 xs
    | otherwise  = x:( dropThird (i + 1) xs)

data List a = Cons a (List a) | Nil

instance Eq a => Eq (List a) where
    (==) (Cons a1 l1)(Cons a2 l2) = if a1 == a2 then (==) l1 l2 else False
    (==) Nil Nil                  = True 
    (==) _   _                    = False
























