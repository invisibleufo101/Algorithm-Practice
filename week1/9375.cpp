#include<bits/stdc++.h>
using namespace std;
int n, m;
string clth, wear;

int main(){
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> m;
        map<string, int>mp;
        for (int j=0; j<m; j++){
            cin >> clth >> wear;
            if (mp[wear]) mp[wear] += 1;
            else mp[wear] = 1;
        }

        int cnt = 1;
        for (auto i: mp){
            cnt *= (i.second + 1);
        }

        cout << cnt - 1 << "\n";
    }

    return 0;
}