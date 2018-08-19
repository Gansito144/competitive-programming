package main

import "fmt"
import "sort"

type RuneSlice []rune

func (r RuneSlice) Len() int {
	return len(r)
}

func (r RuneSlice) Less(i, j int) bool {
	return r[i] < r[j]
}

func (r RuneSlice) Swap(i, j int) {
	r[i], r[j] = r[j], r[i]
}

func sortString(s string) string {
	var r RuneSlice
	r = []rune(s)
	sort.Sort(r)
	return string(r)
}

func main() {
	var a, b, c string
	fmt.Scan(&a)
	fmt.Scan(&b)
	fmt.Scan(&c)

	a = sortString(a + b)
	c = sortString(c)

	if a == c {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
