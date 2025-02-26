#include <bits/stdc++.h>
using namespace std;
int n,m,arr[100004];
int lo,hi,ret,mx;

bool check(int mid){
    if (mx > mid) return 0;

    int temp = mid;
    int cnt = 0;
    for (int i=0; i<n; i++){
        if (mid - arr[i] < 0){
            mid = temp;
            cnt++;
        } 
        mid -= arr[i];
    }
    if (mid != temp) cnt++;

    return m >= cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        hi += arr[i];
        mx = max(mx, arr[i]);
    }

    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (check(mid)){
            hi = mid - 1;
            ret = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << ret << "\n";

    return 0;
}