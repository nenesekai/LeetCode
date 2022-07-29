package main

import "fmt"

func maxSubArray(nums []int) int {
	var max, cur int

	for num := range nums {
		if cur <= 0 { cur = 0 }
		cur += num

		max = 
	}
	return 0
}

func main() {
	var nums = []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}

	var result = maxSubArray(nums)

	fmt.Print(result)
}
