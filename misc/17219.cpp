#include <bits/stdc++.h>
using namespace std;
int n,m;
string site, password, target;
map<string, string>mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> site >> password;
        mp[site] = password;
    }

    for (int i=0; i<m; i++){
        cin >> target;
        if (mp.find(target) != mp.end()){
            cout << mp[target] << "\n";
        }
    }
    return 0;
}