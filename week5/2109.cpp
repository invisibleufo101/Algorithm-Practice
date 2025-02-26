#include <bits/stdc++.h>
using namespace std;
int n,d,p, ret=0;
vector<pair<int,int>>v;
priority_queue<int>pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    if (n == 0){
        cout << 0 << "\n";
        return 0;
    }

    for (int i=0; i<n; i++){
        cin >> p >> d;
        v.push_back({d,p});
    }

    sort(v.begin(), v.end());
    
    int day = v.back().first;
    int iter = n-1;

    while(day > 0){

        while(iter >= 0 && v[iter].first >= day){
            pq.push(v[iter].second);
            iter--;
        }

        if (pq.size()){
            ret += pq.top();
            pq.pop();
        }

        day--;
    }

    cout << ret << "\n";

    return 0;
}