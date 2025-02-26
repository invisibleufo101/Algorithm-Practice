#include <bits/stdc++.h>
using namespace std;
stack<int>stck;
int n,arr[1000004],lis[1000004];
pair<int,int>traces[1000004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(traces, -1, sizeof(traces));

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    int len = 0;
    for(int i=0; i<n; i++){
        auto pos = lower_bound(lis, lis+len, arr[i]);
        int _pos = pos - lis;
        if (*pos == 0) len++; 
        *pos = arr[i];

        traces[i].first = _pos;
        traces[i].second = arr[i];

        cout << "-------------\n";
        for (int j=0; j<len; j++) cout << lis[j] << " ";
        cout << "\n";
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

// 1
// -1000000000