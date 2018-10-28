let xs = [(1,3), (4,3), (2,4), (5,3), (5,6), (3,1)]   

[a+b | (a,b) <- xs]

输出 [4,7,6,8,11,4]

最外层的中括号？是表示输出[]？

head' :: [a] -> a   
head' [] = error "Can't call head on an empty list, dummy!"   
head' (x:_) = x  
x:_  这个冒号的作用作为分号