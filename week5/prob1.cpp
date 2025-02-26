// BOJ #1931
#include <bits/stdc++.h>
using namespace std;
int n, m_start, m_end, cnt=1;
int t_start, t_end;
vector<pair<int,int>>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> m_start >> m_end;
        v.push_back({m_end, m_start});
    }

    sort(v.begin(), v.end());

    t_start = v[0].second; 
    t_end = v[0].first;

    for (int i=1; i<v.size(); i++){
        int next_start = v[i].second;
        if (next_start < t_end) continue;

        t_start = next_start;
        t_end = v[i].first;
        cnt++;
    }

    cout << cnt << "\n";

    return 0;
}