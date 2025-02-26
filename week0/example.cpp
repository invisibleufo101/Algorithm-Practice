#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if (n == 1 || n == 0)
        return 1;                
    
    for (int i=0; i<5; i++) {
        cout << "factorial: " << n << "\n";
        return factorial(n - 1); 
    }
}

int main() {
    int n = 10;
    cout << factorial(n) << "\n";
    return 0;
}