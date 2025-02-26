#include <bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
string s,t;
map<string,int>mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> s;
        mp[s] = 1;
    }

    for (int i=0; i<m; i++){
        cin >> t;
        if (mp.find(t) != mp.end()){
            cnt++;
        }
    }

    cout << cnt << "\n";
    
    return 0;
}