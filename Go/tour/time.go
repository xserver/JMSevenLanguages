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

	fmt.Println(time.Second, time.Minute)

}
