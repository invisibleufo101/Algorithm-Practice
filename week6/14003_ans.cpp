#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX-1;
stack<int>stck;
int n,arr[1000004],lis[1000004];
pair<int,int>traces[1000004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fill(&lis[0], &lis[1000004], INF);
    memset(traces, -1, sizeof(traces));

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    int len = 0;
    for(int i=0; i<n; i++){
        auto pos = lower_bound(lis, lis+len, arr[i]);
        int _pos = pos - lis;
        if (*pos == INF) len++; // If the current number is bigger than the last number in LIS, increase its search length
        *pos = arr[i];

        traces[i].first = _pos;
        traces[i].second = arr[i];
    }

    cout << len << "\n";
    for (int i=n-1; i>=0; i--){
        if (traces[i].first == len - 1){
            stck.push(traces[i].second);
            len--;
        }
    }

    while (stck.size()){
        cout << stck.top() << " ";
        stck.pop();
    }

    return 0;
}