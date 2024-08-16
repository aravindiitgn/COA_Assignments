#include <iostream>
#include <vector>
#include <functional>
#include <ctime>

// Part a: Recursion
long long fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Part b: Loop
long long fibonacci_loop(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Part c: Recursion with Memoization
long long fibonacci_memo_recursive(int n, std::vector<long long>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibonacci_memo_recursive(n - 1, memo) + fibonacci_memo_recursive(n - 2, memo);
    return memo[n];
}

// Part d: Loop with Memoization
long long fibonacci_memo_loop(int n) {
    if (n <= 1) return n;
    std::vector<long long> memo(n + 1, 0);
    memo[1] = 1;
    for (int i = 2; i <= n; ++i) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}

void measure_execution_time(std::function<long long(int)> fibonacci_method, const std::string& method_name) {
    const int N = 50;
    std::cout << "First " << N << " Fibonacci numbers using " << method_name << ":\n";

    struct timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    for (int i = 0; i < N; ++i) {
        std::cout << fibonacci_method(i) << " ";
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

    double elapsed_seconds = end.tv_sec - start.tv_sec;
    double elapsed_nanos = end.tv_nsec - start.tv_nsec;
    double elapsed = elapsed_seconds + elapsed_nanos / 1e9;

    std::cout << "\nCPU time: " << elapsed << " seconds\n\n";
}

int main() {
    measure_execution_time(fibonacci_recursive, "recursion");

    measure_execution_time(fibonacci_loop, "loop");

    measure_execution_time([](int n){
        std::vector<long long> memo(n + 1, -1);
        return fibonacci_memo_recursive(n, memo);
    }, "recursion with memoization");

    measure_execution_time(fibonacci_memo_loop, "loop with memoization");

    return 0;
}
