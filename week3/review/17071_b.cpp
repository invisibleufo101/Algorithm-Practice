#include <bits/stdc++.h>
using namespace std;
int n,k;
int visited[500004];
int step = 1;


int bfs(int u){
    visited[u] = 1;
    queue<int>q;
    q.push(u);

    while(q.size()){
        k += step;
        if (k > 500000) return -1;
        if (visited[k]){
            return step+1;
        }

        int qSize = q.size();
        for (int i=0; i<qSize; i++){
            u = q.front(); q.pop();

            int dir[] = {u + 1, u - 1, u * 2};
            for (int i=0; i<3; i++){
                int nu = dir[i];

                if (nu < 0 || nu > 500000) continue;
                if (visited[nu]) continue;

                if (nu == k){

                    return step - 1;
                }

                visited[nu] = visited[u] + 1;
                q.push(nu);
            }
        }

        step++;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    if (n == k){
        cout << 0;
        return 0;
    }

    cout << bfs(n) << "\n";

    return 0;
}