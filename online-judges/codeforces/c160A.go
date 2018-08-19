package main

import "fmt"
import "sort"

type IntSlice []int

func (p IntSlice) Len() int {
	return len(p)
}

func (p IntSlice) Less(i, j int) bool {
	return p[i] > p[j]
}

func (v IntSlice) Swap(i, j int) {
	v[i], v[j] = v[j], v[i]
}

func main() {
	var n int
	sum, yours := 0, 0
	fmt.Scanf("%d\n", &n)
	var v IntSlice
	v = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &v[i])
		sum += v[i]
		// fmt.Printf("%d %d %d %d\n", n, i, v[i], sum)
	}
	sort.Sort(v)
	// fmt.Printf("%d %d\n", sum, yours)
	for i, vi := range v {
		yours += vi
		sum -= vi
		// fmt.Printf("%d %d\n", i, vi)
		if yours > sum {
			fmt.Printf("%d\n", i+1)
			break
		}
	}
}
