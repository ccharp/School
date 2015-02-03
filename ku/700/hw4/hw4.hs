import Char 

parseLine :: [Char] -> ([Char], Int)
parseLine xs = ( [chars | chars <- xs, isAlpha chars], fromDigits [digitToInt num | num <- xs, isDigit num] )

fromDigits :: [Int] -> Int 
fromDigits = foldl addDigit 0
   where addDigit num d = 10*num + d

mainLoop :: Int -> IO ()
mainLoop x = do putStr "==> "
                print x
                xs <- getLine
                doStuff (parseLine xs) x

doStuff :: ([Char], Int) -> Int -> IO ()
doStuff xs x =  if null (fst xs) then mainLoop (snd xs)   
                 else if fst xs == "help" then do putStrLn "commands: <n>, add <n>, sub <n>, mul <n>, help, quit"
                                                  mainLoop x
                 else if fst xs == "add"  then do print $ x + snd xs
                                                  mainLoop $ x + snd xs
                 else if fst xs == "mul"  then do print $ x * snd xs
                                                  mainLoop $ x * snd xs
                 else putStrLn "Die."
         
--Main function
main = mainLoop 0
				























