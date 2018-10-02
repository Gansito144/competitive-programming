package main

import (
	"fmt"
	"io"
	"os"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	in := io.Reader(os.Stdin)
	var n int
	const oo = 123456789
	const L = 3
	fmt.Fscanf(in, "%d\n", &n)
	// Initialize
	dp := make([]int, 1<<L)
	for mask := range dp {
		dp[mask] = oo
	}
	var cost int
	var juices string
	for i := 0; i < n; i++ {
		fmt.Fscanf(in, "%d %s\n", &cost, &juices)
		var mask int
		for _, j := range juices {
			mask |= 1 << uint(j-'A')
		}
		dp[mask] = min(dp[mask], cost)
	}
	for maskA := 0; maskA < (1 << L); maskA++ {
		for maskB := 0; maskB < (1 << L); maskB++ {
			newCost := dp[maskA] + dp[maskB]
			newMask := maskA | maskB
			dp[newMask] = min(dp[newMask], newCost)
		}
	}
	ans := dp[len(dp)-1]
	if ans == oo {
		ans = -1
	}
	fmt.Println(ans)
}
