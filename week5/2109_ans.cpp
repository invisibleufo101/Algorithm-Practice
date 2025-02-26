#include <bits/stdc++.h>
using namespace std;
int n,pay,day,ret=0;
vector<pair<int,int>>v;
priority_queue<int, vector<int>, greater<int>>pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> pay >> day;
        v.push_back({day, pay});
    }

    sort(v.begin(), v.end());

    
    for (int i=0; i<n; i++){

        pq.push(v[i].second);

        if (pq.size() > v[i].first){
            pq.pop();
        }
    }

    while(pq.size()){

        cout << pq.top() << "\n";

        ret += pq.top();
        pq.pop();
    }

    cout << ret << "\n";

    return 0;
}