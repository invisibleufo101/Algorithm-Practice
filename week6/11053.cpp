#include <bits/stdc++.h>
using namespace std;
int n, arr[1004], dp[1004];
// The smallest value that we can get is 1 
// since there is always going to be at least 1 number
int ret = 1; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    for (int i=0; i<n; i++){
        // We assign 1 to the current number because in worst case scenario, 
        // the length of LIS is 1.
        dp[i] = 1;
        // In this loop, we go through previous numbers (n - 1)
        // If the current previous number (arr[j]) is less than the current number (arr[i]),
        // then we can safely assume that 
        for (int j=0; j<i; j++){
            if (arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
                ret = max(ret, dp[i]);
            }
        }
    }

    cout << ret << "\n";

    return 0;
}