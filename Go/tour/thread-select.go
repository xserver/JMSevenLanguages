package main

import (
	"fmt"
	"time"
)

// 何时执行下个 case ？ 下一个满足时
// 同时满足多个 case ？ 随机选择一个执行
// 都不满足，可以执行 default，避免 block，阻塞
func fibonacci(ch, quit chan int) {
	x, y := 0, 1
	for {
		select {
		case ch <- x:
			x, y = y, x+y
		case <-quit:
			fmt.Println("quit")
			return
		default:
			fmt.Print("    .")
			time.Sleep(50 * time.Millisecond)
		}
	}
}

func main() {
	ch := make(chan int)
	quit := make(chan int)

	go func() {
		for i := 0; i < 28; i++ {
			fmt.Println(<-ch)
			time.Sleep(300 * time.Millisecond)
			if i == 3 {
				quit <- 0
			}
		}
	}()
	
	fibonacci(ch, quit)
}

