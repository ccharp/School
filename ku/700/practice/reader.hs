import Control.Monad


newtype Reader a = Reader (Env -> a)

type Env = [(Int,Int)]

runReader :: Env -> Reader a -> a
runReader env (Reader f) = f env

instance Monad Reader where
    return a = Reader (\ env -> a)
    (Reader f) >>= k
        = Reader (\ env ->
            case (k (f env)) of
              Reader f2 -> f2 env)

 Expr = Var String
      | Lit Int
      | Add Expr Expr
      | Assign String Expr
    deriving Show
