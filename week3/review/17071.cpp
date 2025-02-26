#include <bits/stdc++.h>
using namespace std;
int n,k;
int visited[2][500004];
int step = 1;

int bfs(int u){
    visited[0][u] = 1;
    queue<int>q;
    q.push(u);

    while(q.size()){
        k += step;
        if (k > 500000){
            
            return -1;
        }

        if (visited[step % 2][k]){
            
            return step;
        }

        int qSize = q.size();
        for (int i=0; i<qSize; i++){
            u = q.front(); q.pop();
            
            int dir[] = {u + 1, u - 1, u * 2};
            for (int i=0; i<3; i++){
                int nu = dir[i];

                if (nu < 0 || nu > 500000) continue;
                if (visited[step % 2][nu]) continue;

                visited[step % 2][nu] = visited[(step + 1) % 2][u] + 1;

                if (nu == k){
                    
                    return step;
                }

                q.push(nu);
            }
        }
        step++;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    if (n==k){
        cout << 0;
        return 0;
    }

    cout << bfs(n) << "\n";

    return 0;
}