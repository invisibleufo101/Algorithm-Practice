#include <bits/stdc++.h>
using namespace std;
int n,a,b,len;
vector<pair<int,int>>v;
int lis[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());

    for (int i=0; i<n; i++) cout << v[i].second << " ";
    cout << "\n";
    cout << "------------------\n";

    // In this code, we use lower_bound() in the same way that we used 
    // binary search.
    // With binary search, if the current number is bigger than the last number 
    // in LIS array, we appended it and recorded the last index (j)
    // But here, we use lower_bound() to check whether the number exists in the LIS array
    // If it does, then 
    for (int i=0; i<n; i++){
        auto lowPos = lower_bound(lis, lis+len, v[i].second);
        if (*lowPos == 0) len++;
        *lowPos = v[i].second; // <- insert number

        // Debug
        for (int j=0; j<n; j++) cout << lis[j] << " ";
        cout << "\n";
    }

    cout << n - len << "\n";

    return 0;
}