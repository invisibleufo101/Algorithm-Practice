#include <bits/stdc++.h>
using namespace std;
int t,n;
int one_cnt, zero_cnt;

void solve(int n){
    if (n == 0){
        zero_cnt++;
        return;
    } else if (n == 1){
        one_cnt++;
        return;
    }

    solve(n - 1);
    solve(n - 2);

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;

        one_cnt = 0; zero_cnt = 0;
        solve(n);
        cout << zero_cnt << " " << one_cnt << "\n";
    }
    
    return 0;
}