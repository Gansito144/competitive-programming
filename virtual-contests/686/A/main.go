package main

import "fmt"

func main() {
	var n, x, k int64
	fmt.Scan(&n, &x)
	for i := int64(1); i <= n; i++ {
		var s string
		var xi int64
		fmt.Scan(&s, &xi)
		if s == "+" {
			x += xi
		} else {
			if x < xi {
				k++
			} else {
				x -= xi
			}
		}
	}
	fmt.Printf("%d %d\n", x, k)
}
