#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Dos bucles anidados FOR
void loop1(const vector<vector<int>> &A,const vector<int> &x, vector<int> &y, int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            y[i] += A[i][j] * x[j];
        }
    }
}

void loop2(const vector<vector<int>> &A,const vector<int> &x, vector<int> &y, int n){

    for(int j = 0; j < n; j++){
        for(int i = 0; i< n; i++){
            y[i] += A[i][j] * x[j];
        }
    }
}


int main() {
    int n = 10000 ; // Tamaño de la matriz

    vector<vector<int>> A(n, vector<int>(n, 1));
    vector<int> y(n,0);
    vector<int> x(n,1);

    auto start = high_resolution_clock::now();
    loop1(A, x, y, n);
    auto stop = high_resolution_clock::now();
    cout << "Tiempo del 1er for anidado: " << duration_cast<milliseconds>(stop - start).count() << " ms\n";

    y = vector<int>(n,0);
    start = high_resolution_clock::now();
    loop2(A, x, y, n);
    stop = high_resolution_clock::now();
    cout << "Tiempo del 2do for anidado: " << duration_cast<milliseconds>(stop - start).count() << " ms\n";


    return 0;
}
