#include<bits/stdc++.h>
using namespace std;
int n,m;
string pkmn, q;
map<string, int>mp1;
map<int, string>mp2;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for (int i=1; i<=n; i++){
        cin >> pkmn;

        mp1[pkmn] = i;
        mp2[i] = pkmn;
    }

    for (int i=0; i<m; i++){
        cin >> q;

        if (isalpha(q[0])) cout << mp1[q] << "\n";
        else cout << mp2[atoi(q.c_str())] << "\n";
    }
    return 0;
}