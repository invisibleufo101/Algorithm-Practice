#include <bits/stdc++.h>
using namespace std;
int n;
bool check[4000002];
vector<int>primes;

void getPrimes(int n){
    for (int i=2; i<=n; i++){
        if (check[i]) continue;
        for (int j=2*i; j<=n; j+=i){
            check[j] = 1;
        }
    }

    for (int i=2; i<=n; i++){
        if (check[i] == 0) primes.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    if (n == 1){
        cout << 0 << "\n";
        return 0;
    }

    getPrimes(n);

    int startPoint = 0, endPoint = 0;
    int sum = 0, cnt = 0;
    while(endPoint <= primes.size()){
        if (sum > n){
            sum -= primes[startPoint++];
        } else if (sum < n){
            sum += primes[endPoint++];
        } else if (sum == n){
            cnt++;
            sum += primes[endPoint++];
        }
    }

    cout << cnt << "\n";

    return 0;
}