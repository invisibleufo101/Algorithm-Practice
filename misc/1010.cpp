#include <bits/stdc++.h>
using namespace std;
int t,n,m;
int visited[31][31];

int solve(int m, int n){
    if (m == n ||  n == 0) return 1;
    if (visited[m][n]) return visited[m][n];
    else {
        visited[m][n] = solve(m - 1, n - 1) + solve(m - 1, n);
        return visited[m][n];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--){
        memset(visited, 0, sizeof(visited));
        
        cin >> n >> m;
        if (n == 0 || m == 0){
            cout << 0 << "\n";
        } else {
            cout << solve(m, n) << "\n";
        }
    }

    return 0;
}