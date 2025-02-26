#include <bits/stdc++.h>
using namespace std;
int n;
bool check[4000002];
vector<int>v;

void getPrimes(int n){
    for (int i=2; i<=n; i++){
        if (check[i]) continue;
        for (int j=2*i; j<=n; j+=i){
            check[j] = 1;
        }
    }

    for (int i=2; i<=n; i++){
        if (check[i] == 0) v.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    
    getPrimes(n);

    int hi=0, lo=0;
    int sum=0, cnt=0;
    while(true){
        if (sum >= n) sum -= v[lo++];
        else if (hi == v.size()) break;
        else sum += v[hi++];
        if (sum == n) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}