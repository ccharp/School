{-# LANGUAGE  GADTs, KindSignatures #-}
import Control.Monad

data E where
        Add :: E -> E           -> E
        Num :: Int              -> E
        Var :: String           -> E
        Seq :: E -> E -> E
        Inc :: String -> E 
        Let :: String -> E -> E -> E
   deriving (Show, Eq, Ord)

ex1 = Num 4

ex2 = Add ex1 ex1

ex3 = Let "x" (Num 4)
        $ (Add (Var "x") (Var "x"))

ex3' = Let "x" (Var "x")
        $ (Add (Var "x") (Var "x"))

ex4 = Var "y"



eval0 :: E -> Int
eval0 (Add e1 e2) = eval0 e1 + eval0 e2
eval0 (Num n)     = n
eval0 (Var x)     = error "boom!"
eval0 (Let v e1 e2) = eval0 e2
--eval0 (Seq e1 e2 e3) =

data StateEnv :: * where
        StateEnv :: (String -> Maybe Int) -> StateEnv

data State :: * -> * where
        State :: (StateEnv -> (a,StateEnv)) -> State a


runState :: State a -> StateEnv -> (a,StateEnv)
runState (State f) env = f env

instance Monad State where
        return a = State (\ env -> (a,env))
        (State f) >>= k = State (\ env ->
                                case f env of
                                  (a,env') -> case k a of
                                                State m -> m env')

eval1 :: E -> State Int
--eval1 (Add e1 e2) = liftM2 (+) (eval1 e1) (eval1 e2)
eval1 (Add e1 e2) = do
        v1 <- eval1 e1
        v2 <- eval1 e2
        return (v1 + v2)
eval1 (Num n)     = return n
eval1 (Var x)     = get x
eval1 (Let v e1 e2) = do
        v1 <- eval1 e1
        modify v v1 (eval1 e2)
eval1 (Seq e1 e2) = do 
        v1 <- eval1 e1 
        v2 <- eval1 e2
        return v2 
eval1 (Inc x) = do
        var <- get x
        set x (var + 1)
        return var 
                
modify :: String -> Int -> State a -> State a
modify v i (State m) = State (\ env@(StateEnv f) ->
                let env' = StateEnv (\ x -> if x == v then Just i else f x)
                    (a,_) = m env'
                in  (a,env))


get :: String -> State Int
get x = State (\ st@(StateEnv fn) ->
                             case fn x of
                               Nothing -> error "fail!"
                               Just v -> (v,st))

set :: String -> Int -> State ()
set v i = State (\ env@(StateEnv f) ->
                let env' = StateEnv (\ x -> if x == v then Just i else f x)
                in  (a,env))







































