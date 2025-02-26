#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,t,jewels[300004], ret = 1e18;
ll lo = 1, hi = 0;

bool check(ll mid){
    ll group = 0;

    for (int i=0; i<m; i++){
        group += (jewels[i] / mid);
        if (jewels[i] % mid) group++;
    }

    return n >= group;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> jewels[i];
        hi = max(hi, jewels[i]);
    }

    // We are using binary search to find the minimum envy level

    while(lo <= hi){
        ll mid = (lo + hi) / 2;

        if (check(mid)){
            ret = min(ret, mid);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ret << "\n";

    return 0;
}