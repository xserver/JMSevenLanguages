package main

import (
	"fmt"
	"math"
)

// 参数是一个 func->float64, compute->float64
func compute(fn func(float64, float64) float64) float64 {
	// fn 别名
	return fn(2, 3)
}

func main() {
	// 声明了一个 hypot 函数
	hypot := func(x, y float64) float64 {
		return x + y
		// return math.Sqrt(x*x + y*y)
	}

	fmt.Println(hypot(5, 12))
	fmt.Println(compute(hypot))


	// math.Pow func Pow(x, y float64) float64
	// Pow returns x**y, the base-x exponential of y.
	fmt.Println(compute(math.Pow))
}

