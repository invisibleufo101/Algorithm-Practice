#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll x,y;
ll ret=-1; // <- if ret is not changed b/c we can't change the winrate

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> x >> y;
    ll z = (y * 100) / x; // current win-rate

    ll lo = 1, hi = INT_MAX;
    while (lo <= hi){
        ll mid = (lo + hi) / 2;

        ll winRate = ((y + mid) * 100) / (x + mid);
        
        if (winRate == z) lo = mid + 1;
        else if (winRate > z) {
            ret = mid;
            hi = mid - 1;
        }
    }
    
    cout << ret << "\n";

    return 0;
}