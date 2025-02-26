#include <bits/stdc++.h>
using namespace std;
int n, arrival, t;
vector<pair<int,int>>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arrival >> t;
        v.push_back({arrival, t});
    }

    sort(v.begin(), v.end());

    int startTime = v[0].first;
    int endTime = startTime + v[0].second;

    for (int i=1; i<v.size(); i++){
        int nextArrival = v[i].first;
        int nextTime = v[i].second;

        // If the next cow arrived earlier than the finish time
        if (nextArrival < endTime){
            endTime += nextTime;
        } else if (nextArrival >= endTime){
            endTime = (nextArrival + nextTime);
        }
    }

    cout << endTime << "\n";

    return 0;
}