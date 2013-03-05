main = do
    a <- return "hell"
    b <- return "yeah"
    putStrLn $ a ++ " " ++ b


foo :: Maybe String 
foo = do 
    x <- Just "someCra"
    y <- Just "22"  
    return ( show x ++ y ) 

fool :: Maybe Char
fool = do
    (x:xs) <- Just ""
    return x 

test :: [a] -> [a] 
test = \ list -> reverse list

take' :: Int -> [a] -> [a]
take' x = \ xs -> take x xs 

type Parser a = String -> Maybe (a,String)

failure :: Parser a
failure = \ inp -> Nothing

return' :: a -> Parser a
return' v = \ inp -> Just (v,inp)

item :: Parser Char
item = \ inp -> case inp of
         [] -> Nothing
         (x:xs) -> Just (x,xs)

(+++) :: Parser a -> Parser a -> Parser a
p +++ q = \ inp -> case p inp of
            Nothing -> q inp
            Just (v,out) -> Just (v,out)

parse :: Parser a -> String -> Maybe (a,String)
parse p inp = p inp



