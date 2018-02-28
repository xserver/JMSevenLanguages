package main

import "fmt"


// Slice 其实是指针引用，会修改 array 的数值
// Slices are like references to arrays
func main() {

	// [3]bool{true, true, false}	// array
	// []bool{true, true, false}	// slice 不带长度


	// slices 是 array 可变版
	primes := [6]int{2, 3, 5, 7, 11, 13}

	var s []int = primes[1:4]	//[index, length]
	fmt.Println(s)

	names := [4]string{
		"John",
		"Paul",
		"George",
		"Ringo",
	}

	// length and capacity ，用于 array and slice
	fmt.Printf("len=%d cap=%d %v\n", len(names), cap(names), names)
	fmt.Println(names[0:])

	b := names[1:3]
	b[0] = "XXX"
	fmt.Println(b)
	fmt.Println(names)


	ss := []struct {
		i int
		b bool
	}{
		{2, true},
		{3, false},
		{5, true},
		{7, true},
		{11, false},
		{13, true},
	}
	fmt.Println(ss)
}