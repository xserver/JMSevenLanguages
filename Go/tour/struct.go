package main

import "fmt"

type Vertex struct {
	X int
	Y int
}

func main() {
	v := Vertex{1, 2}
	fmt.Println(v)
	v.X = 4
	fmt.Println(v.X)

	p := &v
	p.X = 1e9	//	隐式间接引用 = (*p).X 
	fmt.Println(v.X)

	v2 = Vertex{X: 1}  // Y:0 is implicit，Y 默认值
	fmt.Println(v2)
	v3 = Vertex{}
	fmt.Println(v3)
}

