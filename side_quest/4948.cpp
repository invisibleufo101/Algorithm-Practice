#include <bits/stdc++.h>
using namespace std;
long long n;
const long long max_n = 246912;
bool check[max_n+1];

void getPrimes(long long max_n){
    for (int i=2; i<=max_n; i++){
        if (check[i]) continue;
        for (int j=2*i; j<=max_n; j+=i){
            check[j] = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    getPrimes(max_n);

    while (cin >> n && n != 0){
        long long cnt = 0;
        for(long long i=n+1; i<=2*n; i++){
            if (check[i] == 0) cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}