package main

import "fmt"

// package level var
var objc, java bool
var name string

// initializers
var a, b int = 1, 2
var c = 3	//	类型推导


const (
	// Create a huge number by shifting a 1 bit left 100 places.
	// In other words, the binary number that is 1 followed by 100 zeroes.
	Big = 1 << 100
	// Shift it right again 99 places, so we end up with 1<<1, or 2.
	Small = Big >> 99
)

func needInt(x int) int { return x*10 + 1 }
func needFloat(x float64) float64 {
	return x * 0.1
}

func main() {
	// function level var
	var i int
	fmt.Println(i, objc, java)
	name = "python"
	fmt.Println(name)


	// Short variable declarations
	// 函数内有效，package 无效
	k := 6
	fmt.Println(k)

	const age = 18
	fmt.Println(needInt(Small))
	fmt.Println(needFloat(Small))
	fmt.Println(needFloat(Big))

}

