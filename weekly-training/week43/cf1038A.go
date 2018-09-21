package main

import "fmt"

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	var s string
	fmt.Scan(&s)
	cnt := make([]int, 26)
	for i := 0; i < N; i++ {
		c := s[i] - 'A'
		cnt[c]++
	}
	ans := N + N
	for i := 0; i < K; i++ {
		if cnt[i] < ans {
			ans = cnt[i]
		}
	}
	fmt.Println(ans * K)
}
