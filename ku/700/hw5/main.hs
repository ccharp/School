-- ghc --make -threaded Main.hs
-- time ./Main +RTS -N4

import Control.Concurrent
import Control.Concurrent.MVar
import System.Random

fib :: Int -> Integer
fib n = if n < 2 then 1 else fib(n-1) + fib(n-2)

data Please = Fib Int | Stop

worker :: MVar Please -> IO ()
worker mVar = do
       -- Example
       r <- randomRIO (1,100)
       print $ "Waiting for " ++ show r ++ " micro seconds\n"
       threadDelay (r * 1000)
       
       tid <- myThreadId 
       -- wait for request to work
       arg <- takeMVar mVar
       case arg of
         Stop -> return ()
         Fib n -> do
	        let ans = fib n
		putStr $ "(" ++ show tid ++ ")fib " 
		      	         ++ show n ++ " = " ++ show ans ++ "\n"
	        worker mVar

main :: IO ()
main = do
     mVar <- newEmptyMVar
     sequence_ [ forkIO (worker mVar)
     	       | i <- [1..4]
	       ]
     print "Starting"	     
     -- Fill Q
     sequence_ [ putMVar mVar (Fib n)
     	       | n <- [1..36]
	       ]
     print "Stopping"

     sequence_ [ putMVar mVar Stop
     	       | n <- [1..4]
	       ]
     print "Done"
