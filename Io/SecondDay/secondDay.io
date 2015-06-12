i := 1
n := 8

a := 0
b := 1
c := 0

//while(i <= n, c println; c = a+b; b=a; a=c; i = i + 1); "sum is " println

while(i <= n, 
	c print; " "print
	c = a+b; 
	b=a; 
	a=c; 
	i = i + 1); "sum is " println

//	a  b  a+b 
//	1  1  2  3  5  8  13  21 


array := List clone
array := list(1, 1)
count ::= 10

//for(计数, 初值, 终值, logic)
for(i, 2, count, 1, array append(array at(i-1) + array at(i-2)) println)


fib := method(n,
		if(n == 1 or n == 2, return 1)
		return fib(n-1) + fib(n-2)
	)

fib(8) println
