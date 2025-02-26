#include <bits/stdc++.h>
using namespace std;
int n,k;
int visited[200002];

void bfs(int u){
    visited[u] = 1;
    
    queue<int>q;
    q.push(u);
    while (q.size()){
        u = q.front();
        q.pop();

        int dir[] = {u - 1, u + 1, u * 2};

        for (int v : dir){
            if (v < 0 || v >= 200002) continue;
            if (visited[v]) continue;

            visited[v] = visited[u] + 1;
            q.push(v);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    bfs(n);

    cout << visited[k] - 1 << "\n";

    return 0;
}