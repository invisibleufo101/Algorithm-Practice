#include <bits/stdc++.h>
using namespace std;
int m,n;

bool isPrime(int n){
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i=3; i*i<=n; i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> m >> n;
    for (int i=m; i<=n; i++){
        if (isPrime(i)) cout << i << "\n";
    }

    return 0;
}
