#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,ret;

// In a SORTED ARRAY, there must be at least K number of elements 
// that are LESS OR EQUAL to B[k].
// Using this info, we can use binary search to find B[k].
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    // Array A's index starts from 1
    // therefore lo should be 1
    // The maximum index that's possible is N*N b/c array A is a 2D array
    ll lo = 1, hi = n*n;

    while (lo <= hi){
        ll mid = (lo + hi) / 2;

        ll cnt = 0;
        // Iterate through each layer (1 ~ N) and find how many numbers in each
        // layer is LESS OR EQUAL to current number
        for (int i=1; i<=n; i++){
            // Use min() to prevent overflow (ceiling)
            // b/c if mid > n, then we have overflow

            // i.e) N = 3, k=7. Mid = 5. i = 1.
            // 5 / 1 = 5 numbers that are less or equal to mid 
            // BUT N only reaches up to 3 therefore we need to put a ceiling to
            // cap off the overflow.
            cnt += min(mid / i, n);

            // if (mid / i > n) cnt += n;
            // else if (mid / i <= n) cnt += mid / i;
        }

        // If the count of numbers that are LESS OR EQUAL to B[k] is lower
        if (cnt < k) lo = mid + 1; // move up the range
        else if (cnt >= k) hi = mid - 1; // else, move down the range
    }

    cout << lo << "\n";

    return 0;
}