#include <bits/stdc++.h>
using namespace std;
int n,deadline,ramen,ret=0;
vector<pair<int,int>>v;
priority_queue<int>pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> deadline >> ramen;
        v.push_back({deadline, ramen});
    }

    sort(v.begin(), v.end());

    int day = v.back().first;
    int iter = n-1;
    
    while(day > 0){

        while(iter >= 0 && v[iter].first >= day){
            pq.push(v[iter].second);
            iter--;
        }

        if(pq.size()){
            ret += pq.top();
            pq.pop();
        }
        day--;
    }

    cout << ret << "\n";

    return 0;
}