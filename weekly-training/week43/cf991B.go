package main

import "fmt"
import "sort"

func main() {
	var n, sum, ans, need int
	fmt.Scan(&n)
	v := make([]int, n)
	for i := range v {
		fmt.Scan(&v[i])
		v[i] *= 2
		sum += v[i]
	}
	need = 9 * n
	sort.Ints(v)
	for i := range v {
		if sum >= need {
			break
		}
		sum += 10 - v[i]
		ans++
	}
	fmt.Println(ans)
}
