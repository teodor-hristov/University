package main

import "fmt"

func Filter(p func(int) bool) func(...int) []int {
	var (
		result = func(nums ...int) []int {
			var returnArray []int

			for i := range nums {
				if p(nums[i]) {
					returnArray = append(returnArray, nums[i])
				}
			}

			return returnArray
		}
	)

	return result
}

func Odd(num int) bool {
	return num%2 != 0
}

func Even(num int) bool {
	return num%2 == 0
}

func main() {

	fmt.Printf("Filter: %v\n", Filter(Odd)(1, 2, 3, 4, 5))
	fmt.Printf("Filter: %v\n", Filter(Even)(1, 2, 3, 4, 5))

}
