#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    cout << "factorial: " << n << "\n";
    if (n == 1 || n == 0) 
        return 1; // <= End condition
    return n * factorial(n-1); // Recursion
}

// Function to see how many times the function calls itself for every recursion step
int fibonacci(int n) {
    cout << "fibonacci: " << n << "\n";
    if (n == 0 || n == 1)
        return n;
        
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 7;
    // cout << factorial(n) << " " << fibonacci(n) << "\n";
    // cout << factorial(n) << "\n";
    cout << fibonacci(n) << "\n";
    return 0;
}