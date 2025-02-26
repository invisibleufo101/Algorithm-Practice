#include <bits/stdc++.h>
using namespace std;
int t,a,b;

int solve(int root, int power){
    int ret = 1;
    while(power--){
        ret = (ret * root) % 10;
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--){
        cin >> a >> b;
        int ret = solve(a,b);

        if (ret == 0) cout << 10 << "\n";
        else cout << ret << "\n";
    }

    return 0;
}