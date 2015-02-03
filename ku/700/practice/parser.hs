import Control.Monad
import Data.Char

data Parser a = P (String -> Maybe (a,String))
-- Deconstructs a Parser to its function

instance Monad Parser where
 -- (>>=) :: Parser a -> (a -> Parser b) -> Parser b
 p1 >>= p2 = P (\ inp ->
                    case runP p1 inp of
                    Nothing -> Nothing
                    Just (v,out) -> runP (p2 v) out)
 -- return :: a -> Parser a
 return v = P (\ inp -> Just (v,inp))

runP :: Parser a -> String -> Maybe (a,String)  
runP (P p) = p

item :: Parser Char
item = P (\ inp -> case inp of
                   [] -> Nothing
                   (x:xs) -> Just (x,xs))

failure :: Parser a
failure = P (\ inp -> Nothing)

(+++) :: Parser a -> Parser a -> Parser a
p +++ q = P (\ inp -> case runP p inp of
               Nothing -> runP q inp
               Just (v,out) -> Just (v,out))

parse :: Parser a -> (String -> Maybe (a,String))
parse p = \ inp -> runP p inp -- how can runP have two parameters? 

p :: Parser (Char,Char)
p = do x <- item
       item
       y <- item
       return (x,y)

sat :: (Char -> Bool) -> Parser Char
sat p = do x <- item
           if p x then 
               return x
           else 
               failure 

digit :: Parser Char 
digit = sat isDigit

char :: Char -> Parser Char 
char x = sat (x ==)

many :: Parser a -> Parser [a] 
many p = many1 p +++ return []

many1 :: Parser a -> Parser [a] 
many1 p = do v <- p
             vs <- many p 
             return (v:vs)

p1 :: Parser String 
p1 = do char '[' 
        d <- digit 
        ds <- many (do char ','
                       digit)
        char ']'
        return (d:ds)
       

--p1 :: Parser (Char,Char)
--p1 = (\ 
