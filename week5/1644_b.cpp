#include <bits/stdc++.h>
using namespace std;
int n;
int max_n = 4000000;
bool check[4000004];

vector<int> getPrimes(int n){
    vector<int>v;

    for (int i=2; i<=n; i++){
        if (check[i]) continue;
        for (int j=2*i; j<=n; j+=i){
            check[j] = 1;
        }
    }

    for (int i=2; i<=n; i++){
        if (check[i] == 0) v.push_back(i);
    }

    return v;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector<int>t = getPrimes(n);

    int cnt = 0;

    for (int i=0; i<t.size(); i++){
        long long sum = 0;
        for (int j=i; j<t.size(); j++){
            sum += t[j];

            if (sum == n){
                cnt++;
                break;
            } else if (sum > 4000000){
                break;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}