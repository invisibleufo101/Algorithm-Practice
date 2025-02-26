#include <bits/stdc++.h>
using namespace std;
int n,t,sum,ret = -10004;

// Basically this code is choosing whether to continue adding the sum
// or ditch the sum and start the sum fresh from the current index
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> t;
        sum += t;
        ret = max(ret, sum);
        if (sum < 0) sum = 0;
    }

    cout << ret << "\n";
    
    return 0;
}