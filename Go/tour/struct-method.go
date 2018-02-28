package main

import (
	"fmt"
)

type Vertex struct {
	X, Y float64
}

// function 是 C 概念里的函数
// method 是 C++ 概念里面的类方法
// So: Methods are functions
// a method is just a function with a receiver argument.

// struct 添加 方法
func (v Vertex) Abs() float64 {
	// value receiver, copy 的副本
	return v.X + v.Y
}

// pointer 添加 方法
func (v *Vertex) Scale(f float64) {
	// pointer receiver, 修改对本体有效
	v.X = v.X * f
	v.Y = v.Y * f
}

// 基础类型 添加 方法
type MyFloat float64
func (f MyFloat) FloatAbs() float64 {
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}


func main() {
	v := Vertex{3, 4}
	fmt.Println(v.Abs())

	v.Scale(2)
	fmt.Println(v)

	f := MyFloat(-2)
	fmt.Println(f.FloatAbs())
}