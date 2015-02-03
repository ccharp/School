--Corbin Charpentier HW 5
{-
safetail :: [a] -> [a] 
safetail [] = []
safetail (x:xs) = xs
-}

{-
safetail :: [a] -> [a] 
safetail xs = 
	if null xs then
		[]
	else
		tail xs 
-}

safetail :: [a] -> [a] 
safetail xs | null xs 	 = []
			| otherwise  = tail xs


