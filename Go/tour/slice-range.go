package main

import "fmt"

var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}

func main() {

	// v is a copy. 是副本
	for i, v := range pow {
		fmt.Printf("2**%d = %d\n", i, v)
	}

	// pow := make([]int, 10)
	for i := range pow {
		fmt.Printf("%d ", i)
		pow[i] = 1 << uint(i) // == 2**i
	}
	fmt.Println()
	for _, value := range pow {
		fmt.Printf("%d\n", value)
	}
}

