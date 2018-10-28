-- 求最大
maximum' :: (Ord a) => [a] -> a   
maximum' [] = error "maximum of empty list"   
maximum' [x] = x   
maximum' (x:xs)    			-- x  是 head, xs 是 tail
    | x > maxTail = x   	-- 如果 x > maxTail 返回 x
    | otherwise = maxTail   -- 否则返回 maxTail
    where maxTail = maximum' xs -- xs (剩余的[]) 递归

{- 
-- 使用 max 返回最大的
maximum' :: (Ord a) => [a] -> a   
maximum' [] = error "maximum of empty list"   
maximum' [x] = x   
maximum' (x:xs) = max x (maximum' xs)
-}

-- 
replicate' :: (Num i, Ord i) => i -> a -> [a]   
replicate' n x   
    | n <= 0    = []   
    | otherwise = x:replicate' (n-1) x


-- 取 a 的前 i 个元素
take' :: (Num i, Ord i) => i -> [a] -> [a]   
take' n _   
    | n <= 0   = []   
take' _ []     = []   
take' n (x:xs) = x : take' (n-1) xs


-- 翻转 list
reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x]


-- 捆绑
zip' :: [a] -> [b] -> [(a,b)]   
zip' _ [] = []   
zip' [] _ = []   
zip' (x:xs) (y:ys) = (x,y):zip' xs ys


-- 快排
quicksort :: (Ord a) => [a] -> [a]   
quicksort [] = []   
quicksort (x:xs) =   
	-- let 绑定了大、小两个式子 [输出 | 输入， 条件]
	-- 把小于 x 的若干项输出 list, 又取 list 的 x:xs 迭代
	let smallerSorted = quicksort [a | a <- xs, a <= x]
		biggerSorted  = quicksort [a | a <- xs, a > x]   
	in 	smallerSorted ++ [x] ++ biggerSorted




{-

-- Objective-C 
- (NSInteger)maximum:(NSArray *)list {
    
    if (list == nil || list.count < 1) {
        return NSNotFound;
    }
    
    if (list.count == 1) {
        return [[list firstObject] integerValue];
    }

    id tail = [list subarrayWithRange:NSMakeRange(1, list.count - 1)];
    NSInteger max = [self maximum:tail];

    NSInteger first = [[list firstObject] integerValue];
    if (first > max) {
        max = first;
    }
    
    return max;
}
-}

