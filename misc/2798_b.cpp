#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[101];
int ret = 0;

void solve(int idx, int cnt, int sum){
    if (idx == n){
        if (cnt == 3){
            if (sum <= m) ret = max(ret, sum);
        }
        return;
    } else if (cnt == 3){
        if (sum <= m) ret = max(ret, sum);
        return;
    }

    solve(idx+1, cnt, sum);
    solve(idx+1, cnt+1, sum+arr[idx]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }    

    solve(0, 0, 0);
    cout << ret << "\n";

    return 0;
}