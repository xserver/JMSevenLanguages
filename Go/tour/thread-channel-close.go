package main

import (
	"fmt"
	"time"
)

func fibonacci(n int, c chan int) {
	x, y := 0, 1
	for i := 0; i < n; i++ {
		c <- x
		x, y = y, x+y

		time.Sleep(300 * time.Millisecond)
	}
	close(c)
}

func main() {
	c := make(chan int, 8)
	go fibonacci(cap(c), c)

	// 等 channel 有数据就读取，直到它被关闭。
	for i := range c {
		fmt.Println(i)
	}
}