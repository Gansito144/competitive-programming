package main

import "fmt"

func main() {
	var n, k, mn int
	fmt.Scan(&n, &k)
	mn = n
	k2p1 := k + k + 1
	kp := k + 1
	ans := 1
	for i := 1; i <= kp; i++ {
		tmp := 1
		j := i
		for {
			if j+k >= n {
				break
			}
			j += k2p1
			tmp++
		}
		if tmp < mn {
			mn = tmp
			ans = i
		}
	}
	fmt.Println(mn)
	for ; ans <= n; ans += k2p1 {
		fmt.Printf("%d ", ans)
	}
	fmt.Println("")
}
