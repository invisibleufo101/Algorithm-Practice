#include <bits/stdc++.h>
using namespace std;
int n,arrival, process;
vector<pair<int,int>>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arrival >> process;
        v.push_back({arrival, process});
    }

    sort(v.begin(), v.end());
    int ret = v[0].first + v[0].second;

    for (int i=1; i<v.size(); i++){
        ret = max(ret, v[0].first);
        ret += v[i].second;
    }

    cout << ret << "\n";

    return 0;
}