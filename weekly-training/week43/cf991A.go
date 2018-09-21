package main

import "fmt"

func main() {
	var A, B, C, D int
	fmt.Scan(&A, &B, &C, &D)
	A -= C
	B -= C
	D -= C
	D -= (A + B)
	// fmt.Printf("A:%d B:%d C:%d D:%d\n", A, B, C, D)
	if A < 0 || B < 0 || D < 1 {
		D = -1
	}
	fmt.Println(D)
}
