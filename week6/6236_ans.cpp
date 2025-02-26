#include <bits/stdc++.h>
using namespace std;
int n,m,arr[100004],lo,hi,ret;

bool check(int mid){
    int cnt = 1, temp = mid;
    for (int i=0; i<n; i++){
        if (mid - arr[i] < 0){
            mid = temp;
            cnt++;
        } 
        mid -= arr[i];
    }

    return m >= cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        lo = max(lo, arr[i]);
    }

    hi = 1000000004;
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (check(mid)){
            ret = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ret << "\n";

    return 0;
}