#include <bits/stdc++.h>
using namespace std;
int t,a,b;
int commons = 1;

bool check(int n){
    if (n <= 1) return 1;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i=3; i*i<=n; i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int getGCD(int a, int b){
    int ret = min(a,b);
    while (ret > 0){
        if (a % ret == 0 && b % ret == 0) break;

        ret--;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> t;
    while (t--){

        cin >> a >> b;

        int commons = getGCD(a,b);
        if (commons == 1){
            long long ret = a * b;
            cout << ret << "\n";
        } else {    
            long long ret = (a / commons) * (b / commons) * commons;
            cout << ret << "\n";
        }
    }

    return 0;
}