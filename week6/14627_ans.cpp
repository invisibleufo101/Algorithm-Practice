#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll s,c,sum,arr[1000004],ret;

bool check(ll onionLen){
    ll cnt = 0;
    for (int i=0; i<s; i++) cnt += (arr[i] / onionLen);
    return cnt >= c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s >> c;
    for (int i=0; i<s; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    ll lo = 1, hi = 1e9;
    while (lo <= hi){
        ll mid = (lo + hi) / (1LL * 2); // <- Type casting long long * long long, not long long * int
        if (check(mid)){
            lo = mid + 1;
            ret = mid;
        } else {
            hi = mid - 1;
        }
    }

    ll ans = sum - ret * c;
    cout << ans << "\n";

    return 0;
}