#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll k,n,wires[10004];
ll lo=1,hi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k >> n;
    for (int i=0; i<k; i++){
        cin >> wires[i];
        hi += wires[i];
    }

    // Binary Search maximum length of each wire
    while (lo <= hi){
        ll mid = (lo + hi) / 2;

        ll cnt = 0;
        for (int i=0; i<k; i++){
            // If current wire length is greater than max length,
            cnt += wires[i] / mid;
        }

        // If cnt is greater than n, that means we need to increase the max length
        // if cnt is less than n, that means wee need to decrease the max length
        if (cnt >= n) lo = mid + 1;
        else if (cnt < n) hi = mid - 1;
    }

    cout << hi << "\n";

    return 0;
}