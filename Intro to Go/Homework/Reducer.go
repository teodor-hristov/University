package main

import "fmt"

func Reducer(initial int, f func(int, int) int) func(...int) int {
	var ret int
	var (
		functionRet = func(args ...int) int {
			for i := range args {
				if initial <= i {
					ret += args[i]
				}
			}
			return ret
		}
	)

	return functionRet
}

func main() {

	sum := Reducer(0, func(a, b int) int { return a + b })
	fmt.Printf("sum(1, 2, 3): %v\n", sum(1, 2, 3))             // 6
	fmt.Printf("sum(5): %v\n", sum(5))                         // 11
	fmt.Printf("sum(100, 101, 102): %v\n", sum(100, 101, 102)) // 314

}
