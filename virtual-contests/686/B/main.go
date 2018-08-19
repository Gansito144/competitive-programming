package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	v := make([]int, n)
	for i := range v {
		fmt.Scan(&v[i])
	}

	for i := 0; i < n; i++ {
		for j := n - 1; j > i; j-- {
			if v[j] < v[j-1] {
				fmt.Println(j, j+1)
				v[j-1], v[j] = v[j], v[j-1]
			}
		}
	}
	//fmt.Println(v)
}
