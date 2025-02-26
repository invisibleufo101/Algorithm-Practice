#include <bits/stdc++.h>
using namespace std;
int n,l,a,b,idx,ret;
vector<pair<int,int>>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l;
    for (int i=0; i<n; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());
    int cnt;
    for(int i=0; i<v.size(); i++){
        if (v[i].second <= idx) continue;
        if (idx < v[i].first){
            cnt = (v[i].second - v[i].first) / l + bool((v[i].second - v[i].first) % l);
            idx = v[i].first + cnt * l;
        } else if (idx >= v[i].first){
            cnt = (v[i].second - idx) / l + bool((v[i].second - idx) % l);
            idx = idx + cnt * l;
        }

        ret += cnt;
    }

    cout << ret << "\n";
    
    return 0;
}