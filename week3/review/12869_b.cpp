#include <bits/stdc++.h>
using namespace std;
int n;
int arr[3];
int damage [6][3] = {
    {-9, -3, -1},
    {-9, -1, -3},
    {-3, -9, -1},
    {-3, -1, -9},
    {-1, -9, -3},
    {-1, -3, -9},
};
int ret = 987654321;

/**
 * Time limit exceeded :(
 * This does work but it just takes too much time
*/

void solve(int a, int b, int c, int cnt){
    if (cnt >= ret){
        return;
    } else if (a == 0 && b == 0 && c == 0){
        ret = min(ret, cnt);
        return;
    }
    
    for (int i=0; i<6; i++){
        int na = max(0, a + damage[i][0]);
        int nb = max(0, b + damage[i][1]);
        int nc = max(0, c + damage[i][2]);

        solve(na, nb, nc, cnt+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    solve(arr[0], arr[1], arr[2], 0);
    cout << ret << "\n";

    return 0;
}