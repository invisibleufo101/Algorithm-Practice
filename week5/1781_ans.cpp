#include <bits/stdc++.h>
using namespace std;
int n, deadline, ramen, ret;
vector<pair<int,int>>v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> deadline >> ramen;
        v.push_back({deadline, ramen});
    }

    // Sort vector by deadline (least -> greatest)
    sort(v.begin(), v.end());

    // Iterate through vector
    // Add the current number of ramen (v[i].second) to ret
    // Push it to prioirty queue (greatest -> least)
    // If # of items that PQ (greatest -> least) holds is greater than current deadline
    // Pop out whatever is the least and subtract that least amount
    for (int i=0; i<v.size(); i++){
        ret += v[i].second;
        pq.push(v[i].second);
        if (pq.size() > v[i].first){
            ret -= pq.top();
            pq.pop();
        }
    }

    cout << ret << "\n";

    return 0;
}