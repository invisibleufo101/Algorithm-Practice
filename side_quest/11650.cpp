#include <bits/stdc++.h>
using namespace std;
int n,x,y;
vector<pair<int,int>>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x >> y;
        v.push_back({x,y});
    }

    sort(v.begin(), v.end());

    for (auto it : v) cout << it.first << " " << it.second << "\n";

    return 0;
}