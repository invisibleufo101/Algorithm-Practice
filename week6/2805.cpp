#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,trees[1000004];
ll lo,hi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> trees[i];
        // lo = min(lo, trees[i]);
        hi += trees[i];
    }

    while (lo <= hi){
        ll mid = (lo + hi) / 2;

        ll sum = 0;
        for (int i=0; i<n; i++){
            // If trees are higher than H, sum up the cut tree length
            if (trees[i] > mid) sum += trees[i] - mid;
        }

        if (sum >= m) lo = mid + 1;
        else if (sum < m) hi = mid - 1;
    }

    cout << hi << "\n";

    return 0;
}