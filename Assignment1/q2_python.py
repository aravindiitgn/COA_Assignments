import numpy as np
import time
import sys

def matrix_multiply(A, B, N):
    C = np.zeros((N, N), dtype=A.dtype)
    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i, j] += A[i, k] * B[k, j]
    return C

def main():
    if len(sys.argv) != 3:
        print("Usage: python script_name.py <matrix_size> <data_type: int|double>")
        sys.exit(1)

    
    N = int(sys.argv[1])
    data_type = sys.argv[2]

    if data_type not in ("int", "double"):
        print("Invalid data type. Please specify 'int' or 'double'.")
        sys.exit(1)

    if data_type == "int":
        print(f"Matrix multiplication for size {N}x{N} (Integer):")
        A = np.fromfunction(lambda i, j: i + j, (N, N), dtype=int)
        B = np.fromfunction(lambda i, j: i + j, (N, N), dtype=int)

        start_time = time.time()
        C = matrix_multiply(A, B, N)
        end_time = time.time()
       
    elif data_type == "double":
        print(f"Matrix multiplication for size {N}x{N} (Double):")
        A = np.fromfunction(lambda i, j: i + j, (N, N), dtype=float)
        B = np.fromfunction(lambda i, j: i + j, (N, N), dtype=float)

        start_time = time.time()
        C = matrix_multiply(A, B, N)
        end_time = time.time()

    print(f"Elapsed time: {end_time - start_time:.2f} seconds")

if __name__ == "__main__":
    main()
