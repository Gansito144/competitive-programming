package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	sum := n * (n + 1) / 2

	ans := 0

	for gcd := 2; gcd < n; gcd++ {
		cmp := sum - gcd
		if cmp > 0 && cmp%gcd == 0 {
			ans = gcd
			break
		}
	}

	if ans == 0 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
		fmt.Printf("%d", n-1)
		for i := 1; i <= n; i++ {
			if i == ans {
				continue
			}
			fmt.Printf(" %d", i)
		}
		fmt.Printf("\n1 %d\n", ans)
	}
}
