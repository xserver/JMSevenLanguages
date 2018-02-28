package main

import "fmt"

type I interface {
	M()
}

type T struct {
	S string
}

func (t *T) M() {
	if t == nil {
		fmt.Println("<nil> 未初始化")
		return
	}
	fmt.Println(t.S)
}

func main() {
	var i I
	describe(i) // (<nil>, <nil>)
	// i.M()	// 会报错，因为找不到具体方法。设计理念问题。也可以忽略

	var t *T
	i = t  // 此时 t 并未初始化
	describe(i)  // (<nil>, *main.T)
	i.M()	// 能调用，interface 的关键，是把方法关联起来，但无实体执行

	i = &T{"hello"}
	describe(i)
	i.M()
}

func describe(i I) {
	fmt.Printf("(%v, %T)\n", i, i)
}