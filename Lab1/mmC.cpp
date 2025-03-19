#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void multMat(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


int main() {
    int n = 1000;

    vector<vector<int>> A(n, vector<int>(n, 1));
    vector<vector<int>> B(n, vector<int>(n, 1));
    vector<vector<int>> C(n, vector<int>(n, 0));

    auto start = high_resolution_clock::now();
    multMat(A, B, C, n);
    auto stop = high_resolution_clock::now();
    cout << "Tiempo de multiplicación clásica: " << duration_cast<milliseconds>(stop - start).count() << " ms\n";
}
