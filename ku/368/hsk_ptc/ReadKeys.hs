import System.IO
import Control.Concurrent

main = do
     hSetBuffering stdin NoBuffering	-- input does not buffer
     hSetBuffering stdout NoBuffering	-- output does not buffer
     hSetEcho stdin False
     loop

nonBlockingGetChar :: IO (Maybe Char)
nonBlockingGetChar = do
     b <- hReady stdin
     if b then do
          ch <- getChar
	  return (Just ch)
       else do
       	  return Nothing

loop = do
     threadDelay (50 * 1000)
     opt_ch <- nonBlockingGetChar
     case opt_ch of
       Nothing -> do
            putStr "."
       Just ch -> do
            putStr [ch]
     loop
