import Test.QuickCheck 

qSort :: [Int] -> [Int] 
qSort [] = []
qSort (x:xs) = qSort ys ++ [x] ++ qSort zs
               where 
                ys = [a | a <- xs, a <= x]
                zs = [b | b <- xs, b > x]

is_sorted :: [Int] -> [Bool]
is_sorted [] = [True]
is_sorted (x:xs) | xs == [] = [True]
                 | otherwise = (x <= (head xs)):(is_sorted xs)

prop_sort1 :: Int -> Bool
prop_sort1 x = qSort [x] == [x]  
    where
        types = (x :: Int)

prop_sort2 :: [Int] -> Bool
prop_sort2 xs = length xs == ( length  (qSort xs))
    where
        types = (xs :: [Int])

prop_sort3 :: [Int] -> Bool
prop_sort3 xs = and (is_sorted (qSort xs))
    where 
        types = (xs :: [Int])

prop_sort4 :: [Int] -> Bool
prop_sort4 xs = qSort xs == (qSort (qSort xs))
    where
        types = (xs :: [Int])


{- Property1 tests the base case list of size 1. Property2 verifies that a sorted list 
 - is the same length of of the unsorted list. If they are not, the sort has failed somewhere. 
 - Property3 verfies that the list progresses from lower indeces to high in ascending order, 
 - which, by definition, is a sorted list. Property4 basically says that sorted a sorted list
 - results in a sorted list. The most important property (and really the only property we need) 
 - is property3, as it can test all other properties. -}
                
                
                
                
                
                
                
                
                
                
                             
