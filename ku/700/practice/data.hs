data Tree a = Branch (Tree a) (Tree a) | Leaf a 

fringe :: Tree a -> [a]
fringe (Leaf x) = [x]
fringe (Branch left right) = fringe left ++ fringe right 

 
