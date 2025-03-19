package main

import (
	"fmt"
	"time"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func blockMatrixMultiplication(A, B, C [][]int, n, blockSize int) {
	for i := 0; i < n; i += blockSize {
		for j := 0; j < n; j += blockSize {
			for k := 0; k < n; k += blockSize {
				for ii := i; ii < min(i+blockSize, n); ii++ {
					for jj := j; jj < min(j+blockSize, n); jj++ {
						for kk := k; kk < min(k+blockSize, n); kk++ {
							C[ii][jj] += A[ii][kk] * B[kk][jj]
						}
					}
				}
			}
		}
	}
}


func main() {
	n := 1000
	blockSize := 64 

	A := make([][]int, n)
	B := make([][]int, n)
	C := make([][]int, n)
	for i := 0; i < n; i++ {
		A[i] = make([]int, n)
		B[i] = make([]int, n)
		C[i] = make([]int, n)
		for j := 0; j < n; j++ {
			A[i][j] = 1
			B[i][j] = 1
		}
	}

	start = time.Now()
	blockMatrixMultiplication(A, B, C, n, blockSize)
	elapsed = time.Since(start)
	fmt.Printf("Tiempo de multiplicación por bloques: %v\n", elapsed)
}
