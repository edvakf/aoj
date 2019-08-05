package main

import (
	"bufio"
	"fmt"
	"os"
)

func parent(i int) int {
	return i / 2
}
func left(i int) int {
	return i * 2
}
func right(i int) int {
	return i*2 + 1
}

func maxHeapify(A []int, H int, i int) {
	l := left(i)
	r := right(i)

	var largest int
	if l <= H && A[l] > A[i] {
		largest = l
	} else {
		largest = i
	}
	if r <= H && A[r] > A[largest] {
		largest = r
	}

	if largest != i {
		tmp := A[i]
		A[i] = A[largest]
		A[largest] = tmp
		maxHeapify(A, H, largest)
	}
}

func buildMaxHeap(A []int, H int) {
	for i := H / 2; i >= 1; i-- {
		maxHeapify(A, H, i)
	}
}

func main() {
	var H int
	_, _ = fmt.Scanf("%d", &H)

	A := make([]int, H+1)

	r := bufio.NewReader(os.Stdin)
	for i := 1; i <= H; i++ {
		_, _ = fmt.Fscanf(r, "%d", &A[i])
	}

	buildMaxHeap(A, H)

	w := bufio.NewWriter(os.Stdout)
	for i := 1; i <= H; i++ {
		_, _ = fmt.Fprintf(w, " %d", A[i])
	}
	w.Flush()
	_, _ = fmt.Printf("\n")
}
