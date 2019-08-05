package main

import "fmt"

func main() {
	var n int
	_, _ = fmt.Scanf("%d", &n)

	a := make([]int, n+1)

	for i := 1; i <= n; i++ {
		_, _ = fmt.Scanf("%d", &a[i])
	}

	for i := 1; i <= n; i++ {
		fmt.Printf("node %d: key = %d, ", i, a[i])
		if i != 1 {
			fmt.Printf("parent key = %d, ", a[i/2])
		}
		if i*2 <= n {
			fmt.Printf("left key = %d, ", a[i*2])
		}
		if i*2+1 <= n {
			fmt.Printf("right key = %d, ", a[i*2+1])
		}
		fmt.Printf("\n")
	}
}
