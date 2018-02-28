package main

import "fmt"

func main() {
	m := make(map[string]int)

	m["Answer"] = 42
	fmt.Println("The value:", m["Answer"])

	m["Answer"] = 48
	fmt.Println("The value:", m["Answer"])

	delete(m, "Answer")
	fmt.Println("The value:", m["Answer"])

	// 通过双赋值检测某个键是否存在：
	v, ok := m["Answer"]
	fmt.Println("The value:", v, "Present?", ok)
	// 不存在，value 默认为 0，
	
}

