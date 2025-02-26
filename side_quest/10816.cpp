#include <bits/stdc++.h>
using namespace std;
int n,m;
int t,x;
map<int,int>mp;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t;
        mp[t]++;
    }
    
    cin >> m;
    for (int i=0; i<m; i++){
        cin >> x;
        if (mp.find(x) != mp.end()){
            cout << mp[x] << " ";
        } else {
            cout << 0 << " ";
        }
    }

    return 0;
}