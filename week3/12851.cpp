#include <bits/stdc++.h>
using namespace std;
int n,k; // n -> subin, k -> bro
int tel_dist;
int visited[200002];
long long cnt[200002];

void bfs(int u){
    visited[u] = 1;
    cnt[u] = 1;
    
    queue<int>q;
    q.push(u);
    while (q.size()){
        u = q.front();
        q.pop();

        int dir[] = {u - 1, u + 1, u * 2};

        for (int v : dir){
            if (v < 0 || v >= 200002) continue;
            if (visited[v] == 0){
                visited[v] = visited[u] + 1;
                cnt[v] += cnt[u];
                q.push(v);
            } else if (visited[v] == visited[u] + 1){
                cnt[v] += cnt[u];
            }

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
    cout << cnt[k] << "\n";

    return 0;
}