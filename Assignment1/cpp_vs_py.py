import matplotlib.pyplot as plt

# Matrix sizes
sizes = [64, 128, 256, 512, 1024]

# C++ Elapsed Times (seconds)
cpp_int = [0.00124548, 0.0129012, 0.0916474, 0.775512, 7.02308]
cpp_double = [0.0013017, 0.0112976, 0.100147, 0.817398, 12.1445]

# Python Elapsed Times (seconds)
py_int = [0.06, 0.48, 3.93, 33.79, 300.83]
py_double = [0.07, 0.55, 4.14, 36.24, 319.81]

# Plot
plt.figure(figsize=(10, 6))

plt.plot(sizes, cpp_int, marker='o', label='C++ Integer')
plt.plot(sizes, cpp_double, marker='o', label='C++ Double')
plt.plot(sizes, py_int, marker='o', label='Python Integer')
plt.plot(sizes, py_double, marker='o', label='Python Double')

plt.title('C++ vs Python Execution Time for Matrix Multiplication')
plt.xlabel('Matrix Size (N)')
plt.ylabel('Time (seconds)')
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.savefig('cpp_vs_python_comparison.png')
plt.show()
