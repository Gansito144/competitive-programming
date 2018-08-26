package main

import "fmt"
import "sort"

type IntSlice []int

func (p IntSlice) Len() int {
	return len(p)
}

func (p IntSlice) Less(i, j int) bool {
	return p[i] < p[j]
}

func (v IntSlice) Swap(i, j int) {
	v[i], v[j] = v[j], v[i]
}

func main() {
	var n int
	fmt.Scanf("%d\n", &n)
	var v IntSlice
	v = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &v[i])
	}
	sort.Sort(v)
	for _, vi := range v {
		fmt.Printf("%d ", vi)
	}
	fmt.Println()
}
