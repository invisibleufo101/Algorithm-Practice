#include <bits/stdc++.h>
using namespace std;
int n, cnt=0, mn=987654321;
int visited[1000004];

void bfs(int u, int cnt){
    visited[u] = 1;
    queue<pair<int,int>>q;
    q.push({u,cnt});
    while(q.size()){
        tie(u,cnt) = q.front();
        q.pop();

        if (u == 1){
            mn = min(mn, cnt);
            return;
        }

        if (visited[u]) continue;

        if (u % 3 == 0){
            int nu = u / 3;
            visited[nu] = 1;
            q.push({nu, cnt+1});
        } 

        if (u % 2 == 0){
            int nu = u / 2;
            visited[nu] = 1;
            q.push({nu, cnt+1});
        }

        int nu = u - 1;
        visited[nu] = 1;
        q.push({nu, cnt+1});
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    solve(n, 0);
    cout << mn << "\n";

    return 0;
}