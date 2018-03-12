package main

import (
	"fmt"
	"time"
)

func main() {

	// (A)
	// time.AfterFunc(2 * time.Second, func() {
	//     fmt.Println("after 2 second")
	// })
	// fmt.Println("AfterFunc 不阻塞")
	// time.Sleep(3 * time.Second)
	// fmt.Println("sleep 3 second")


	// (B) Timer object
	// fmt.Println(time.Now())
	// timer := time.NewTimer(2 * time.Second)
	// <-timer.C
	// fmt.Println(time.Now())

	// (C) time.After() returns timer.C internally
	// fmt.Println(time.Now())
	// <-time.After(2 * time.Second)
	// fmt.Println(time.Now())
	// 使用 channel 的机制

	// (D)
	// fmt.Println(time.Now())
	// time.Sleep(2 * time.Second)
	// fmt.Println(time.Now())
}

