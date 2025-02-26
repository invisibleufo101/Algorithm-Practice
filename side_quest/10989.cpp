#include <bits/stdc++.h>
using namespace std;
int n,t;
map<int,int>mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t;
        mp[t]++;
    }

    for (auto it : mp){
        for (int j=0; j<it.second; j++){
            cout << it.first << "\n";
        }
    }

    return 0;
}