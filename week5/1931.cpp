#include <bits/stdc++.h>
using namespace std;
int n, startTime, endTime;
vector<pair<int,int>>v;

// I did this while preparing for SSAFY LMAO (I didn't get in RIP)
// Sort the meeting times by their end times (least -> greatest)
// Start off with the first meeting's end time
// If the next meeting's start time is equal or later than the current end time,
// increase cnt & designate the current endTime as that meeting's end time.
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> startTime >> endTime;
        v.push_back({endTime, startTime});
    }

    sort(v.begin(), v.end());
    int meetEnd = v[0].first;
    int cnt = 1;
    for (int i=1; i<v.size(); i++){
        if (v[i].second >= meetEnd){
            cnt++;
            meetEnd = v[i].first;
        }
    }

    cout << cnt << "\n";

    return 0;
}