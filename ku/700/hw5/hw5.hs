import Control.Concurrent
import Control.Concurrent.MVar
import System.Random 



takeFork :: MVar Int -> IO Int 
takeFork fork = takeMVar fork 

philosophize :: [MVar ()] -> Int -> IO ()
philosophize mVars i = do
    r <- randomRIO (0,4)
    -- Take a fork
    fork <- takeMVar (mVars !! r)
    -- put fork back
    putMVar (mVars !! r) fork 

    philosophize mVars r 

main = do 
    mVars <- [newEmptyMVar | x <- [1..5]]
    sequence_ [forkIO (philosophize mVars i) | i <- [1..5]]    
    getLine
    return ()
