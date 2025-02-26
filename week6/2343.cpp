#include <bits/stdc++.h>
using namespace std;
int n,m,arr[100004],lo,hi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        lo = max(lo, arr[i]);
        hi += arr[i];
    }

    // Binary Search the size
    // Lo = biggest blueray size in the array
    // Hi = total of ALL the blueray sizes
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        // Check if the current size limit can accomodate th
        int sum = 0, cnt = 0;
        for (int i=0; i<n; i++){
            if (sum + arr[i] > mid){
                sum = 0;
                cnt++;
            }
            sum += arr[i];
        }
        // Consider the remaining sum
        if (sum) cnt++;
        
        // If the number of groups is bigger than M,
        // then the current size limit is too small so move up to a upper half
        
        // Else if the number of groups is less or equal to M,
        // then the current size limit is too big, so move to the lower half
        if (cnt > m){
            lo = mid + 1;
        } else if (cnt <= m){
            hi = mid - 1;
        }
    }

    cout << lo << "\n";

    return 0;
}