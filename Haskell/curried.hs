-- Curried Functions

multThree :: (Num a) => a -> a -> a -> a 
multThree x y z = x * y * z
{-
	let one = multThree 9 
	one 2 3 
	54   -- one 2 3 => multThree 9 2 3


	let two = one 2 -- two 10 => one 2 10 
	two 10 			--        => multThree 9 2 10
	180
	把空格放到两个东西之间，称作函数调用。
-}

applyTwice :: (a -> a) -> a -> a   
applyTwice f x = f (f x)

{-

	ghci> applyTwice (multThree 2 2) 9   
	144 

144 = 16 * 9， 16 = 4 * 4


applyTwice :: (a -> a) -> a -> a   
applyTwice f x = f (f x)

*Main> :t (+3)
(+3) :: Num a => a -> a

案例
applyTwice (+ 3) 10

-- (+ 3) 是两部分  + = f , 3 = x

f x = f (f x) 即是 + 3 = + (+ 3), 用第一次的 + 3 返回的结果a，再 + a

-}