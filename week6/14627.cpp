#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll s,c,arr[1000004];
ll lo=1,hi = LLONG_MAX - 1;
ll sum;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s >> c;
    for (int i=0; i<s; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    // Binary search the maximum length of green onion 
    // that can satisfy the number of fried chicken orders
    while (lo <= hi){
        ll mid = (lo + hi) / 2;

        ll cnt = 0;
        for (int i=0; i<s; i++) cnt += (arr[i] / mid);
        
        if (cnt < c) hi = mid - 1;
        else if (cnt >= c) lo = mid + 1;
    }

    ll ret = sum - hi * c;
    cout << ret << "\n";

    return 0;
}