#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll m,n,arr[1000004];
ll lo=1, hi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        hi += arr[i];
    }

    while (lo <= hi){
        ll mid = (lo + hi) / 2;

        ll cnt = 0;
        for (int i=0; i<n; i++){
            cnt += (arr[i] / mid);
        }

        if (cnt < m) hi = mid - 1;
        else if (cnt >= m) lo = mid + 1;
    }
    
    cout << hi << "\n";

    return 0;
}