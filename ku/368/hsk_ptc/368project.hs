import System.Console.ANSI
import Control.Concurrent
import System.IO
import System
import System.Random

type Cord = (Int, Int)

snakeInit = [(4, 5), (4, 4),(4, 3),(4, 2)]

sleep :: IO ()
sleep = do
    threadDelay 550000

writeAt :: Cord -> String -> IO()
writeAt (x, y) str = do 
    setCursorPosition x y
    putStr str

exit :: IO ()
exit = do 
    writeAt (30, 30) "You Lose"
    exitWith ExitSuccess

showBounds :: IO ()
showBounds = do
    sequence_ [writeAt (x, 0)  "|" | x <- [0..25]]
    sequence_ [writeAt (x, 40) "|" | x <- [0..25]]
    sequence_ [writeAt (0, y)  "-" | y <- [1..39]]
    sequence_ [writeAt (25, y) "-" | y <- [1..39]]

showObjects :: [Cord] -> IO ()
showObjects cords = sequence_ [writeAt c "x" | c <- cords] -- sequence_ evalutes actions then ignores the result

advSnakeUp :: [Cord] -> [Cord]
advSnakeUp ((x1, y1):cords) = (x1, y1 - 1):(x1, y1):(init cords)

advSnakeDown :: [Cord] -> [Cord]
advSnakeDown ((x1, y1):cords) = (x1, y1 + 1):(x1, y1):(init cords)

advSnakeLeft :: [Cord] -> [Cord]
advSnakeLeft ((x1, y1):cords) = (x1 + 1, y1):(x1, y1):(init cords)

advSnakeRight :: [Cord] -> [Cord]
advSnakeRight ((x1, y1):cords) = (x1 - 1, y1):(x1, y1):(init cords)

moveSnake :: [Cord] -> IO [Cord]
moveSnake cords = do 
    opt_ch <- nonBlockingGetChar
    case opt_ch of
       Nothing -> do
            return $ advSnakeIdle cords
       Just ch -> do
            if opt_ch == Just 'w' then do return $ advSnakeUp cords
                             else if opt_ch == Just 'a' then do return $ advSnakeLeft cords
                             else if opt_ch == Just 's' then do return $ advSnakeDown cords
                             else if opt_ch == Just 'd' then do return $ advSnakeRight cords
                             else do return $ advSnakeIdle cords --bad key input
    

advSnakeIdle :: [Cord] -> [Cord]
advSnakeIdle ((x1, y1):cords) 
    | y1 > fst (head cords) = (x1, y1 + 1):restOfSnake
    | y1 < snd (head cords) = (x1, y1 - 1):restOfSnake
    | x1 > fst (head cords) = (x1 + 1, y1):restOfSnake
    | x1 < snd (head cords) = (x1 - 1, y1):restOfSnake
    where restOfSnake = (x1, y1):(init cords)
      
checkBounds :: Cord -> IO ()
checkBounds (x, y) 
    | x < 1     = exit
    | y < 1     = exit
    | x > 24    = exit
    | y > 39    = exit 
    | otherwise = writeAt (30, 30) "Good"

nonBlockingGetChar :: IO (Maybe Char)
nonBlockingGetChar = do
     b <- hReady stdin
     if b then do
          ch <- getChar
	  return (Just ch)
       else do
       	  return Nothing                      

newApplePos :: Cord
newApplePos = (5, 5) --(randomR (2, 23), randomR (2, 38))

checkApple :: Cord -> Cord -> Bool
checkApple sHead apple 
    | sHead == apple = True
    | otherwise = False

growSnake :: [Cord] -> [Cord]
growSnake ((x1, y1):cords) 
    | y1 > fst (head cords) = (x1, y1 + 1):restOfSnake
    | y1 < snd (head cords) = (x1, y1 - 1):restOfSnake
    | x1 > fst (head cords) = (x1 + 1, y1):restOfSnake
    | x1 < snd (head cords) = (x1 - 1, y1):restOfSnake
    where restOfSnake = (x1, y1):cords 

snake :: [Cord] -> Cord -> IO()
snake cords apple = do
    clearScreen
    checkBounds (head cords)
    showObjects cords
    showBounds
    sleep
    if checkApple (head cords) apple == True
        then
            snake ((growSnake cords) (5,5)) --should be newApplePos, (5,5) for debugging
        else
            snake ((moveSnake cords) apple)

main :: IO ()
main = do
    hSetBuffering stdin NoBuffering	    -- input does not buffer
    hSetBuffering stdout NoBuffering	-- output does not buffer
    hSetEcho stdin False
    snake snakeInit newApplePos


