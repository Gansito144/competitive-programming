package main

import (
	"fmt"
)

func main() {
	var n int
	var s string
	fmt.Scan(&n, &s)
	prv := s[0] - 1
	ans := 0
	for i := range s {
		if s[i] == prv {
			ans++
			continue
		}
		prv = s[i]
	}
	fmt.Println(ans)
}
