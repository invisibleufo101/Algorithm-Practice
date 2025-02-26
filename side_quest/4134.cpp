#include <bits/stdc++.h>
using namespace std;
long long t,a;

bool isPrime(long long n){
    if(n <= 1) return 0;
    for (int i=2; i <= sqrt(n); i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--){
        cin >> a;

        long long iter = a;

        while (true){
            if (isPrime(iter)){
                cout << iter << "\n";
                break;
            }

            iter++;
        }
    }

    return 0;
}