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

func MapReducer(initial int, mapper func(int) int, reducer func(int, int) int) func(...int) int {
	var res int
	var (
		ret = func(args ...int) int {
			var temp []int = Mapper(mapper)(args...)
			res += Reducer(initial, reducer)(temp...)

			return res
		}
	)

	return ret
}

func main() {
	powerSum := MapReducer(0, func(v int) int { return v + 1 }, func(a, v int) int { return a + v })

	fmt.Printf("powerSum: %v\n", powerSum(-1, -2, 3, 4)) // 30
	fmt.Printf("powerSum: %v\n", powerSum(-1, -2, 3, 4)) // 60
	fmt.Printf("powerSum: %v\n", powerSum())             // 60
}
