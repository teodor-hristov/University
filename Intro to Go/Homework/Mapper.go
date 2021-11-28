package main

import "fmt"

func Mapper(m func(int) int) func(...int) []int {
	var (
		result = func(nums ...int) []int {
			var returnArray []int

			for index := range nums {
				returnArray = append(returnArray, m(nums[index]))
			}

			return returnArray
		}
	)

	return result
}

func main() {
	double := Mapper(func(a int) int { return 2 * a })

	fmt.Printf("double: %v\n", double(1, 2, 3)) // [2, 4, 6]
	fmt.Printf("double: %v\n", double(4, 5, 6)) // [8, 10, 12]
}
