#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,budget[10004];
ll lo=1,hi,ret;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> budget[i];
        hi += budget[i];
    }
    cin >> m;

    // Binary search the budget limit
    while (lo <= hi){
        ll mid = (lo + hi) / 2;

        ll sum = 0; ll cmp = 0;
        for (int i=0; i<n; i++){
            if (budget[i] > mid){
                sum += mid;
                cmp = max(cmp, mid);
            } else if (budget[i] <= mid){
                sum += budget[i];
                cmp = max(cmp, budget[i]);
            }
        }

        if (sum <= m){
            lo = mid + 1;
            ret = max(ret, cmp);
        } else if (sum > m) hi = mid - 1;
        
    }

    cout << ret << "\n";

    return 0;
}