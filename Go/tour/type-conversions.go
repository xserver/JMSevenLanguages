package main

import (
	"fmt"
	"math"
)

func main() {
	var x, y int = 3, 4
	var f float64 = math.Sqrt(float64(x*x + y*y))
	var z uint = uint(f)
	fmt.Println(x, y, z)


	i := 42
	//	需要显式转化 conversion 优点
	// k := float64(i)
	var k float64 := i
	fmt.Println(k)
}