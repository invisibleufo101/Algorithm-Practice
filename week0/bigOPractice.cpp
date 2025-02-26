#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

int doubleForLoop(int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            // cout << j << "\n";
            cnt++;
        }
    }
    return cnt;
}

int nAndM(int n, int m){
    int a = 1;
    for (int i=0; i<n; i++){
        a *= i;
    }

    for (int j=0; j<m; j++){
        a *= j;
    }

    return a;
}

void solve(int N){
    cnt++;
    cout << cnt << "\n";
    if (N == 0){
        return;
    }

    for (int i=0; i<3; i++){
        solve(N-1);
    }

    return;
}

int main(){
    // cout << doubleForLoop(3) << "\n";
    
    solve(3);
    
    return 0;
}