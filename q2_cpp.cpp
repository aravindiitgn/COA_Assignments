#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>  // For std::atoi

using namespace std;

template <typename T>
void matrixMultiply(const vector<vector<T>>& A, const vector<vector<T>>& B, vector<vector<T>>& C, int N) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                C[i][j] += A[i][k] * B[k][j];
}

template <typename T>
void initializeMatrix(vector<vector<T>>& matrix, int N) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            matrix[i][j] = static_cast<T>(i + j);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <matrix_size> <data_type: int|double>\n";
        return 1;
    }

    int N = std::atoi(argv[1]);
    if (N <= 0) {
        cout << "Error\n";
        return 1;
    }

    string dataType = argv[2];

    if (dataType == "int") {
        cout << "Matrix multiplication for size " << N << "x" << N << " (Integer):\n";
        vector<vector<int>> A(N, vector<int>(N));
        vector<vector<int>> B(N, vector<int>(N));
        vector<vector<int>> C(N, vector<int>(N, 0));

        initializeMatrix(A, N);
        initializeMatrix(B, N);

        auto start = chrono::high_resolution_clock::now();
        matrixMultiply(A, B, C, N);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> elapsed = end - start;
        cout << "Elapsed time: " << elapsed.count() << " seconds\n";
    } else if (dataType == "double") {
        cout << "Matrix multiplication for size " << N << "x" << N << " (Double):\n";
        vector<vector<double>> D(N, vector<double>(N));
        vector<vector<double>> E(N, vector<double>(N));
        vector<vector<double>> F(N, vector<double>(N, 0.0));

        initializeMatrix(D, N);
        initializeMatrix(E, N);

        auto start = chrono::high_resolution_clock::now();
        matrixMultiply(D, E, F, N);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> elapsed = end - start;
        cout << "Elapsed time: " << elapsed.count() << " seconds\n";
    } else {
        cout << "Error";
        return 1;
    }

    return 0;
}
