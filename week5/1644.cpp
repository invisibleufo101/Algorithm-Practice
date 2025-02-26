#include <bits/stdc++.h>
using namespace std;
int n;
int max_n = 4000000;
bool check[4000004];
vector<int>v;

void getPrimes(int x){
    
    for (int i=2; i<=x; i++){
        if (check[i]) continue;
        for (int j=2*i; j<=x; j+=i){
            check[j] = 1;
        }
    }

    for (int i=2; i<=x; i++){
        if (check[i] == 0){
            v.push_back(i);
        }
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

    int cnt = 0;
    int startPoint = 0;
    int endPoint = 0;
    int sum = 0;

    while(endPoint <= v.size()){

        // if (sum >= n){
        //     sum -= v[startPoint];
        //     startPoint++;
        // } 
        
        // if (sum < n){
        //     sum += v[endPoint];
        //     endPoint++;
        // }

        // if (sum == n){
        //     cnt++;
        // } 

        if (sum > n){
            sum -= v[startPoint];
            startPoint++;
        }

        if (sum < n){
            sum += v[endPoint];
            endPoint++;
        }

        if (sum == n){
            cnt++;
            endPoint++;
        }
    }

    cout << cnt << "\n";

    return 0;
}