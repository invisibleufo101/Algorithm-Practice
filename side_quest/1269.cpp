#include <bits/stdc++.h>
using namespace std;
int n,m,x,t;
map<int, int>mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> x;
        mp[x]++;
    }

    for (int i=0; i<m; i++){
        cin >> t;
        mp[t]++;
    }

    int cnt = 0;
    for (auto it : mp){
        if (it.second >= 2) cnt++;
    }

    int ret = n - cnt + m - cnt;
    cout << ret << "\n";
    
    return 0;
}