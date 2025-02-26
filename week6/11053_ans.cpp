#include <bits/stdc++.h>
using namespace std;
int n,arr[1004], dp[1004], ret=1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    for (int i=0; i<n; i++){
        dp[i] = 1;
        int maxVal = 0;
        for (int j=0; j<i; j++){
            if (arr[j] < arr[i] && dp[j] > maxVal){
                maxVal = dp[j];
            }
        }

        dp[i] += maxVal;
        ret = max(ret, dp[i]);
    }

    cout << ret << "\n";

    return 0;
}