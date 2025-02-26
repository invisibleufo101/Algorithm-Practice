#include <bits/stdc++.h>
using namespace std;
int n,arr[100004],dp[100004];

// This problem requires you to think in small steps
// The dp array calculates the maximum sum for 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    int mx = arr[0];
    dp[0] = arr[0];
    for (int i=1; i<n; i++){
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        mx = max(mx, dp[i]);
    }
    
    cout << mx << "\n";

    return 0;
}