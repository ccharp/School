import Control.Monad 

newtype State a = State (Env -> (a,Env))

runState :: State a -> Env -> (a,Env)
runState (State f) env = f env 

get :: State Env 
get = State (\ env -> (env,env))

set :: Env -> State ()
set env = State(\ _ -> ((),env))

readVar :: String -> State Int 
readVar v = do 
    env <- get 
    case lookup v env of 
        Nothing -> fail $ "cannot find " ++ v 
        Just i -> return i

writeVar :: String -> Int -> State ()
writeVar v i = do 
    env <- get 
    set (updateEnv v i env)


