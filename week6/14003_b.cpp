#include <bits/stdc++.h>
using namespace std;
int n,arr[1000004], traces[1000004];
vector<pair<int,int>>lis;
vector<int>v;

void getTraces(int idx){
    if (idx == -1) return;
    v.push_back(arr[idx]);
    getTraces(traces[idx]);
}

int binSearch(int lo, int hi, int target){
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (lis[mid].first >= target) hi = mid - 1;
        else if (lis[mid].first < target) lo = mid + 1;
    }
    return lo;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(traces, -1, sizeof(traces));

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    
    for (int i=0; i<n; i++){

        int pos = binSearch(0, lis.size() - 1, arr[i]);
        
        if (pos == lis.size()) lis.push_back({arr[i], i});
        else lis[pos] = {arr[i], i};

        // Records the previous index of the element (LIS[pos - 1].second)
        // As the next trace in the traces array
        if (pos > 0) traces[i] = lis[pos - 1].second; 
    }

    // lis.back() will always point to the greatest number in the given sequence
    getTraces(lis.back().second);

    cout << v.size() << "\n";
    for (int i=v.size()-1; i>=0; i--) cout << v[i] << " ";

    return 0;
}