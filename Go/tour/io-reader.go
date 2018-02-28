package main

import (
	"fmt"
	"io"
	"strings"
)

// 练习
// https://tour.go-zh.org/methods/22
// https://tour.go-zh.org/methods/23 

func main() {
	r := strings.NewReader("Hello, Reader!")

	b := make([]byte, 8)
	for {
		n, err := r.Read(b)
		fmt.Printf("1 n = %v err = %v b = %v\n", n, err, b)
		fmt.Printf("2 b[:n] = %q\n", b[:n])
		if err == io.EOF {
			break
		}
	}
}

