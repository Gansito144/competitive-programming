package main

import "fmt"

func main() {
	var n, sa, sb, vi int
	fmt.Scan(&n)
	for i := 1; i <= n; i++ {
		fmt.Scan(&vi)
		sa += vi
	}
	for i := 1; i <= n; i++ {
		fmt.Scan(&vi)
		sb += vi
	}
	ans := "Yes"
	if sb > sa {
		ans = "No"
	}
	fmt.Println(ans)
}
