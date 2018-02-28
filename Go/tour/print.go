package main

import "fmt"

import (
	"math"
)

func main() {
    fmt.Printf("hello, world\n")

    fmt.Printf("%d = %d\n", 10, 11)

    fmt.Printf("%q is %v \n", "lock", len("lock"))

    fmt.Println("a", "z", 12)

    // Interface values
    // v = value， T = type
    fmt.Printf("(%v, %T)\n", math.Pi, math.Pi)

    var i I
    describe(i)
}

// 需要一个实现
type I interface {
	M()
}

func describe(i I) {
	fmt.Printf("(%v, %T)\n", i, i)
}

type T struct {
	S string
}

func (t *T) M() {
	fmt.Println(t.S)
}