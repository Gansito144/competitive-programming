package main

import (
	"bufio"
	"fmt"
	"os"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	in := bufio.NewReader(os.Stdin)
	var n, x, y, ans int
	fmt.Fscanf(in, "%d\n", &n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(in, "%d %d\n", &x, &y)
		ans = max(ans, x+y)
	}
	fmt.Println(ans)
}
