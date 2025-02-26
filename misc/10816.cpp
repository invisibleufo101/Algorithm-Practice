#include <bits/stdc++.h>
using namespace std;
int n,m,t,arr[500004];
vector<int>ret;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    cin >> m;
    for (int i=0; i<m; i++){
        cin >> t;

        int lo = lower_bound(arr, arr+n, t) - arr;
        int hi = upper_bound(arr, arr+n, t) - arr;
        ret.push_back(hi - lo);
    }

    for (int i : ret) cout << i << " ";

    return 0;
}