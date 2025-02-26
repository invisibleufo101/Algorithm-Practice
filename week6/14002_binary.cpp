#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,arr[1004],lis[1004];
pair<int,int>traces[1004];
stack<int>stck;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill(&lis[0], &lis[1004], INF);

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    int len = 0;
    for (int i=0; i<n; i++){
        auto lowPos = lower_bound(lis, lis+len, arr[i]);
        int pos = lowPos - lis;
        if (*lowPos == INF) len++; // If number is higher than the bigest number in LIS, increase search length
        *lowPos = arr[i]; // Designate the number to its corresponding index within LIS array
        traces[i].first = pos;
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