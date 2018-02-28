package main

import "fmt"

func sum(s []int, c chan int) {
	sum := 0
	for _, v := range s {
		sum += v
	}
	c <- sum // 将和送入 c
}

// Channels are a typed conduit，带有类型的管道
func main() {
	s := []int{2, 3, 5, -9, 3, 0}
	c := make(chan int)

	fmt.Println(s[:len(s)/2])
	go sum(s[:len(s)/2], c)

	fmt.Println(s[len(s)/2:])
	go sum(s[len(s)/2:], c)

	// fmt.Println(c)
	x, y := <-c, <-c // 从 c 中接收
	// 管道中的数据，看哪个 routine 先执行完

	fmt.Println(x, y)


	// 加 buffer
	ch := make(chan int, 2)
	ch <- 1
	ch <- 2
	// ch <- 3	//	channel full，满了
	fmt.Println(<-ch)
	fmt.Println(<-ch)
}

