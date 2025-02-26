#include <bits/stdc++.h>
using namespace std;
int n,m,t;
map<int,int>mp;

// Counting -> Map OR Array
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> t;
        mp[t]++;
    }

    for (int i=0; i<m; i++){
        cin >> t;
        mp[t]++;
    }

    int cnt = 0;
    for (auto it : mp) if (it.second == 1) cnt++;

    cout << cnt << "\n";

    return 0;
}