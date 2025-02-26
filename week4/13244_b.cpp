#include <bits/stdc++.h>
using namespace std;
int t,n,m,a,b;
vector<int>adj[1004];
int visited[1004];

void solve(int u){
    visited[u] = 1;
    for (int v : adj[u]){
        if (visited[v]) continue;

        solve(v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--){
        // Reset for next round
        memset(visited, 0, sizeof(visited));
        for (int i=0; i<1004; i++){
            adj[i].clear();
        }

        cin >> n >> m;
        for (int i=0; i<m; i++){
            cin >> a >> b;
            adj[b].push_back(a);
            adj[a].push_back(b);
        }

        int componentCnt = 0;

        for (int i=1; i<=n; i++){
            if (!visited[i]){
                componentCnt++;
                solve(i);
            }
        }

        if (m == n-1 && componentCnt == 1){
            cout << "tree\n";
        } else {
            cout << "graph\n";
        }
    }
    return 0;
}