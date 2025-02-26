#include <bits/stdc++.h>
using namespace std;
int n;
double arr[10004], dp[10004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cout << setprecision(3) << fixed;

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    double ret = arr[0];
    dp[0] = arr[0];
    for (int i=1; i<n; i++){
        dp[i] = max(dp[i-1] * arr[i], arr[i]);
        ret = max(ret, dp[i]);
    }

    cout << ret << "\n";

    return 0;
}