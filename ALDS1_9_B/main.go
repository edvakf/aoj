package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"os"
	"runtime"
	"runtime/pprof"
)

var cpuprofile = flag.String("cpuprofile", "", "write cpu profile to `file`")
var memprofile = flag.String("memprofile", "", "write memory profile to `file`")

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
	flag.Parse()
	if *cpuprofile != "" {
		f, err := os.Create(*cpuprofile)
		if err != nil {
			log.Fatal("could not create CPU profile: ", err)
		}
		defer f.Close()
		if err := pprof.StartCPUProfile(f); err != nil {
			log.Fatal("could not start CPU profile: ", err)
		}
		defer pprof.StopCPUProfile()
	}

	var H int
	_, _ = fmt.Scanf("%d", &H)

	A := make([]int, H+1)

	// for i := 1; i <= H; i++ {
	// _, _ = fmt.Scanf("%d", &A[i])
	// }

	r := bufio.NewReader(os.Stdin)
	for i := 1; i <= H; i++ {
		_, _ = fmt.Fscanf(r, "%d", &A[i])
	}

	// scanner := bufio.NewScanner(os.Stdin)
	// scanner.Split(bufio.ScanWords)
	// i := 1
	// for scanner.Scan() {
	// 	m, err := strconv.Atoi(string(scanner.Bytes()))
	// 	if err != nil {
	// 		panic(err)
	// 	}
	// 	A[i] = m
	// 	i++
	// }
	// if err := scanner.Err(); err != nil {
	// 	panic(err)
	// }

	buildMaxHeap(A, H)

	w := bufio.NewWriter(os.Stdout)
	for i := 1; i <= H; i++ {
		// _, _ = fmt.Printf(" %d", A[i])
		// _, _ = fmt.Fprintf(os.Stdout, " %d", A[i])
		_, _ = fmt.Fprintf(w, " %d", A[i])
		// os.Stdout.WriteString(" ")
		// os.Stdout.WriteString(strconv.Itoa(A[i]))
	}
	w.Flush()
	_, _ = fmt.Printf("\n")

	if *memprofile != "" {
		f, err := os.Create(*memprofile)
		if err != nil {
			log.Fatal("could not create memory profile: ", err)
		}
		defer f.Close()
		runtime.GC() // get up-to-date statistics
		if err := pprof.WriteHeapProfile(f); err != nil {
			log.Fatal("could not write memory profile: ", err)
		}
	}
}
