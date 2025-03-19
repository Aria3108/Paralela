package main

import (
	"fmt"
	"time"
)


// Multiplicación de matrices clásica
func matrixMultiplication(A, B, C [][]int, n int) {
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			C[i][j] = 0
			for k := 0; k < n; k++ {
				C[i][j] += A[i][k] * B[k][j]
			}
		}
	}
}


func main() {
	n := 512 
	blockSize := 64 

	// Inicializar matrices
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


	// Evaluación de la multiplicación clásica
	start := time.Now()
	matrixMultiplication(A, B, C, n)
	elapsed := time.Since(start)
	fmt.Printf("Tiempo de multiplicación clásica: %v\n", elapsed)
}
