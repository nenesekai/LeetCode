package main

import "fmt"

func min(a int, b int) int {

	if a < b {
		return a
	} else {
		return b
	}

}

func maxArea(height []int) int {
	max := 0

	for i := 0; i < len(height)-1; i++ {

		if (len(height)-1-i)*height[i] > max {
			for j := i + 1; j < len(height); j++ {

				area := min(height[i], height[j]) * (j - i)

				if area > max {
					max = area
				}

			}
		}

	}

	return max
}

func main() {
	container := []int{1, 8, 6, 2, 5, 4, 8, 3, 7}

	fmt.Println(maxArea(container))
}
