package main

import (
	"fmt"
	"time"
)

func say(s string) {
	for i := 0; i < 4; i++ {
		time.Sleep(100 * time.Millisecond)
		fmt.Println(s)
	}
}

func main() {
	// 开启线程
	go say("world")

	// say("world")
	say("hello")	// 主线程
}

