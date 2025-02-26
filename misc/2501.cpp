#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int>v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    long long sqred = pow(n,2);

    for (int i=1; i<=n; i++){
        if (sqred % i == 0){
            v.push_back(i);

            if (i != sqred / i){
                v.push_back(n / i);
            }
        }
    }

    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    it - v.begin();
    for (int i : v) cout << i << "\n";

    // if (v[k-1]){
    //     cout << v[k-1] << "\n";
    // } else {
    //     cout << 0 << "\n";
    // }

    return 0;
}