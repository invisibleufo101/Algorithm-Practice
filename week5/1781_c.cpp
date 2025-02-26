#include <bits/stdc++.h>
using namespace std;
int n,deadline, ramen;
vector<pair<int,int>>v;
priority_queue<int, vector<int>, greater<int>>pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> deadline >> ramen;
        v.push_back({deadline, ramen});
    }
    sort(v.begin(), v.end());
    int ret = 0;
    for (int i=0; i<v.size(); i++){

        pq.push(v[i].second);
        if (pq.size() > v[i].first){
            pq.pop();
        }
    }

    while(pq.size()){
        ret += pq.top();
        pq.pop();
    }

    cout << ret << "\n";

    return 0;
}