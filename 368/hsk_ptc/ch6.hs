--Power function
pow :: Int -> Int -> Int
pow x 1 = x
pow x n = x * pow (x) (n-1) 

--Length, drop, and init
length' :: [a] -> Int
length' [] = 0
length' (_:xs) = 1 + length xs

drop' :: Int -> [a] -> [a] 
drop' 0 xs     = xs
drop' n (_:xs) = drop' (n-1) xs  

init' :: [a] -> [a] 
init' [_]    = []
init' (x:xs) = x:init xs  

--and, cocnat, replicate, !!, elem
and' :: [Bool] -> Bool
and' []     = True 
and' (x:xs) | x == False = False
            | x == True  = and' xs

concat' :: [[a]] -> [a]
concat' []     = []
concat' (x:xs) = x ++ concat xs

replicate' :: a -> Int -> [a]
replicate' _ 0 = []
replicate' x n = x:replicate' x (n-1)

get :: [a] -> Int -> a
get (x:xs) 1 = x
get (x:xs) n = get xs (n-1)

elem' :: Eq a => a -> [a] -> Bool
elem' _ [] = False
elem' a (x:xs) | x == a    = True
               | otherwise = elem' a xs

--merge sort
halve :: [a] -> ([a], [a])
halve xs = splitAt (div (length xs) 2) xs

merge :: Ord a => [a] -> [a] -> [a] 
merge [] _ = []
merge _ [] = []
merge (x:xs) (y:ys) | x < y     = x:y:merge xs ys
                    | otherwise = y:x:merge xs ys

msort :: Ord a => [a] -> [a] 
msort []  = []
msort [x] = [x]
msort xs  = merge (msort xs1) (msort ys1)
    where
        (xs1, ys1) = halve xs 






























