#include<bits/stdc++.h>
using namespace std;
int n,k,t, res = -10000004;
int psum[100001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;

    for (int i=1; i<=n; i++){
        cin >> t;
        psum[i] = psum[i-1] + t;
    }

    for (int i=k; i<=n; i++){
        res = max(res, psum[i] - psum[i - k]);
    }

    cout << res << "\n";

    return 0;
}