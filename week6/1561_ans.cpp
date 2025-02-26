#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,rides[10004],ret;
ll lo, hi = 60000000004;

bool check(ll time){
    ll cnt = m;
    for (int i=0; i<m; i++){
        cnt += (time / rides[i]);
    }
    return cnt >= n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<m; i++) cin >> rides[i];

    if (n <= m){
        cout << n;
        return 0;
    }

    while (lo <= hi){
        ll mid = (lo + hi) / 2;
        if (check(mid)){
            ret = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    ll cnt = m;
    for (int i=0; i<m; i++){
        cnt += ((ret - 1) / rides[i]);
    }

    for (int i=0; i<m; i++){
        if (ret % rides[i] == 0) cnt++;
        if (cnt == n){
            cout << i + 1 << "\n";
            break;
        }
    }

    return 0;
}