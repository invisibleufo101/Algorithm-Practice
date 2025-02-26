#include <bits/stdc++.h>
using namespace std;
int t,n,m,a[20004],b[20004];

int binSearch(int lo, int hi, int target){
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (b[mid] >= target) hi = mid - 1;
        else if (b[mid] < target) lo = mid + 1;
    }

    return lo;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while(t--){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        cin >> n >> m;

        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<m; i++) cin >> b[i];

        sort(a, a+n); sort(b, b+m);

        int cnt = 0;
        for (int i=0; i<n; i++){
            cnt += binSearch(0, m-1, a[i]);
        }

        cout << cnt << "\n";
    }
    return 0;
}