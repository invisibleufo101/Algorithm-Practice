#include <bits/stdc++.h>
using namespace std;
int n,nums[12], pls, minu, mult, divi;
int mx = -1000000001;
int mn = 1000000001;

void solve(int idx, int sum, int pls, int minu, int mult, int divi){
    if (idx == n-1){
        mx = max(mx, sum);
        mn = min(mn, sum);
        return;
    }

    if (pls) solve(idx+1, sum + nums[idx+1], pls--, minu, mult, divi); 
    if (minu) solve(idx+1, sum - nums[idx+1], pls, minu--, mult, divi);
    if (mult) solve(idx+1, sum * nums[idx+1], pls, minu, mult--, divi);
    if (divi) solve(idx+1, sum / nums[idx+1], pls, minu, mult, divi--);

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) cin >> nums[i];
    cin >> pls >> minu >> mult >> divi;

    solve(0, nums[0], pls, minu, mult, divi);

    cout << mx << "\n" << mn << "\n";

    return 0;
}