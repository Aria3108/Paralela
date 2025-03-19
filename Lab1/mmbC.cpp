#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;


// Multiplicación de matrices por bloques
void multMatBloques(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int n, int blockSize) {
    for (int i = 0; i < n; i += blockSize) {
        for (int j = 0; j < n; j += blockSize) {
            for (int k = 0; k < n; k += blockSize) {
                for (int ii = i; ii < min(i + blockSize, n); ii++) {
                    for (int jj = j; jj < min(j + blockSize, n); jj++) {
                        for (int kk = k; kk < min(k + blockSize, n); kk++) {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }
}


int main() {
    int n = 10000 ; // Tamaño de la matriz
    int blockSize = 64; // Tamaño del bloque

    vector<vector<int>> A(n, vector<int>(n, 1));
    vector<vector<int>> B(n, vector<int>(n, 1));
    vector<vector<int>> C(n, vector<int>(n, 0));

    // Evaluación de la multiplicación por bloques
    auto start = high_resolution_clock::now();
    multMatBloques(A, B, C, n, blockSize);
    auto stop = high_resolution_clock::now();
    cout << "Tiempo de multiplicación por bloques: " << duration_cast<milliseconds>(stop - start).count() << " ms\n";

}