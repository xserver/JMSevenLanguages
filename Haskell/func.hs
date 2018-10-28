-- 匹配模式
lucky :: (Integral a) => a -> String
lucky 7 = "LUCKY NUMBER SEVEN!"
lucky x = "Sorry, you're out of luck, pal!"

--递归
factorial :: (Integral a) => a -> a   
factorial 0 = 1   
factorial n = n * factorial (n - 1)  

-- tuple
addVectors :: (Num a) => (a, a) -> (a, a) -> (a, a)   
addVectors (x1, y1) (x2, y2) = (x1 + x2, y1 + y2) 

-- 冒号作用
tell :: (Show a) => [a] -> String   
tell [] = "The list is empty"   
tell (x:[]) = "The list has one element: " ++ show x   
tell (x:y:[]) = "The list has two elements: " ++ show x ++ " and " ++ show y   
tell (x:y:_) = "This list is long. The first two elements are: " ++ show x ++ " and " ++ show y  

-- as 模式， all 
capital :: String -> String   
capital "" = "Empty string, whoops!"   
capital all@(x:xs) = "The first letter of " ++ all ++ " is " ++ [x] 


-- 匹配模式
sayMe :: (Integral a) => a -> String   
sayMe 1 = "One!"   
sayMe 2 = "Two!"   
sayMe 3 = "Three!"   
sayMe x = "Not between 1 and 3"  


-- guard 检查一个值的某项属性是否为真
bmiTell :: (RealFloat a) => a -> a -> String   
bmiTell weight height   
    | weight / height ^ 2 <= 18.5 = "You're underweight, you emo, you!"   
    | weight / height ^ 2 <= 25.0 = "You're supposedly normal. Pffft, I bet you're ugly!"   
    | weight / height ^ 2 <= 30.0 = "You're fat! Lose some weight, fatty!"   
    | otherwise                 = "You're a whale, congratulations!"

-- level up, where 
-- Guards & Where
bmiTell2 :: (RealFloat a) => a -> a -> String   
bmiTell2 weight height   
    | bmi <= skinny = "You're underweight, you emo, you!"   
    | bmi <= normal = "You're supposedly normal. Pffft, I bet you're ugly!"   
    | bmi <= fat    = "You're fat! Lose some weight, fatty!"   
    | otherwise     = "You're a whale, congratulations!"   
	where bmi = weight / height ^ 2   -- where 可以不要
          skinny = 18.5   
          normal = 25.0   
          fat = 30.0

-- 中缀函数
myCompare :: (Ord a) => a -> a -> Ordering   
a `myCompare` b   
    | a > b     = GT   
    | a == b    = EQ   
    | otherwise = LT  


-- case 语句
describeList :: [a] -> String   
describeList xs = "The list is " ++ case xs of []  -> "empty."   
                                               [x] -> "a singleton list."    
                                               xs  -> "a longer list." 
                                                
case expression of pattern -> result   
                   pattern -> result 
{-

describeList :: [a] -> String   
describeList xs = "The list is " ++ what xs   
    where what [] = "empty."   
          what [x] = "a singleton list."   
          what xs = "a longer list."  

-}


