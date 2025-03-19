package main

import (
    "fmt"
    "time"
)

func loop1(A [][]int, x, y []int, n int) {
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            y[i] += A[i][j] * x[j]
        }
    }
}

func loop2(A [][]int, x, y []int, n int) {
    for j := 0; j < n; j++ {
        for i := 0; i < n; i++ {
            y[i] += A[i][j] * x[j]
        }
    }
}

func main() {
    n := 1000 // Reducido para evitar consumo excesivo de memoria

    A := make([][]int, n)
    for i := range A {
        A[i] = make([]int, n)
        for j := range A[i] {
            A[i][j] = 1
        }
    }

    y := make([]int, n)
    x := make([]int, n)
    for i := range x {
        x[i] = 1
    }

    start := time.Now()
    loop1(A, x, y, n)
    fmt.Printf("Tiempo del 1er for anidado: %v ms\n", time.Since(start).Milliseconds())

    y = make([]int, n) 
    start = time.Now()
    loop2(A, x, y, n)
    fmt.Printf("Tiempo del 2do for anidado: %v ms\n", time.Since(start).Milliseconds())
}
