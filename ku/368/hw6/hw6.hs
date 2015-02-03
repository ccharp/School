{- Corbin Charpentier 
   HW 6 -}

guess::Int -> IO()
guess n = do 
    putStr "Make a guess: "
    m <- getLine
    if n == read m then putStrLn "Correct!"
                   else if n > read m then do putStrLn "higher" 
                                              guess n
                   else do putStrLn "lower"
                           guess n 
