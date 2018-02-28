package main

import "fmt"

type Person struct {
	Name string
	Age  int
}

/*
type Stringer interface {
    String() string
}
有这么一个接口，任何 type 都可以实现，和 objc 的 description 一样意义。
*/
func (p Person) String() string {
	return fmt.Sprintf("%v (%v years)", p.Name, p.Age)
}

func main() {
	a := Person{"Arthur Dent", 42}
	z := Person{"Zaphod Beeblebrox", 9001}
	fmt.Println(a, z)
}

