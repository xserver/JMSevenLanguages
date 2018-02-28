package main

import "fmt"

func adder() func(int) int {
	sum := 0
	fmt.Printf("0 init sum = %d\n", sum)
	return func(x int) int {
		sum += x
		fmt.Printf("1 sum = %d  x = %d\n", sum, x)
		return sum
	}
}

func main() {

	// 初始化了一个函数，函数作为一个变量，提升至类似一个类
	pos := adder()
	fmt.Println("----")
	for i := 0; i < 4; i++ {
		fmt.Println(i)
		fmt.Printf("pos = %d\n", pos(i))
		fmt.Println("----")
	}

	fmt.Println("============")
	one, two := adder(), adder()
	for i := 0; i < 4; i++ {
		fmt.Println(
			one(i),
			two(-2*i),
		)
	}
}

