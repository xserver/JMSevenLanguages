package main

import "fmt"

func main() {
	var i interface{} = "hello"

	s := i.(string)
	fmt.Println(s)

	s, ok := i.(string)
	fmt.Println(s, ok)	// hello true

	// 直接取一个类型不对的 value，会报错，强类型思路。
	// 对比 map-mutating.go，ok 的用法
	// f = i.(float64) // panic
	// fmt.Println(f)

	// 加上 ok，作安全判断
	f, ok := i.(float64)
	fmt.Println(f, ok)	// 0 false


}

