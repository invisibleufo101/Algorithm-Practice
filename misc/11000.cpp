#include <bits/stdc++.h>
using namespace std;
int n,s,e;
vector<pair<int,int>>v;
priority_queue<int, vector<int>, greater<int>>pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> s >> e;
        v.push_back({s,e});
    }

    sort(v.begin(), v.end());

    for (int i=0; i<n; i++){
        pq.push(v[i].second);
        if (pq.top() <= v[i].first) pq.pop();
    }

    cout << pq.size() << "\n";

    return 0;
}