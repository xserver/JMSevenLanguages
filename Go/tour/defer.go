package main

import "fmt"

func main() {
	defer fmt.Println("我后执行")

	fmt.Println("先执行")


	fmt.Println("counting")

	for i := 0; i < 10; i++ {
		defer fmt.Println(i)
	}

	fmt.Println("done")
}

