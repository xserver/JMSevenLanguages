package main

import (
	"fmt"
	"time"
)

/*
type Stringer interface {
    String() string
}

type Error interface {
    Error() string
}

built-in interface : 内建接口
*/

type MyError struct {
	When time.Time
	What string
}

func (e *MyError) Error() string {
	return fmt.Sprintf("at %v, %s", e.When, e.What)
}

func run() error {
	return &MyError{
		time.Now(),
		"it didn't work",
	}
}

func main() {
	if err := run(); err != nil {
		fmt.Println(err)
	}

	fmt.Println(Sqrt(2))
	fmt.Println(Sqrt(-2))
}

type ErrNegativeSqrt float64

func (e ErrNegativeSqrt) Error() string {
	return fmt.Sprintf("error = %d", e)
}

func Sqrt(x float64) (float64, error) {
	
	if x < 0 {
		return 0, ErrNegativeSqrt(x)
	} else {
		return 0, nil
	}
}

