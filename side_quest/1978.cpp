#include <bits/stdc++.h>
using namespace std;
int n,x;

bool isPrime(int n){
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i=3; i*i <= n; i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(){
    cin >> n;
    int cnt = 0;
    for (int i=0; i<n; i++){
        cin >> x;
        if (isPrime(x)){
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}