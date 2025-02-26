#include <bits/stdc++.h>
using namespace std;
int n,k;
int arr[100001];
int visited[100001];
int cnt[100001];

void bfs(int u){
    visited[u] = 1;
    cnt[u] = 1;

    queue<int>q;
    q.push(u);
    while(q.size()){
        u = q.front();
        q.pop();

        int dir[] = {u*2, u+1, u-1};
        for (int i=0; i<3; i++){
            int nu = dir[i];

            if (nu < 0 || nu >= 100001) continue;

            if (!visited[nu]){
                visited[nu] = visited[u] + 1;
                q.push(nu);
                cnt[nu] += cnt[u];
            // Checking if the route that's visiting this node came by the shortest route
            // The first IF statement already marked down the shortest steps it took to get to that certain node
            // We are only looking to add how many ways there are to reach this certain node in the shortest number of steps possible.
            // Therefore, by adding 1 to visited[u], we can know whether this route has taken the same number of steps 
            // as the one that's visited this node with the shortest number of steps.
            } else if (visited[nu] == visited[u] + 1){
                cnt[nu] += cnt[u];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    if (n == k){
        cout << 0 << "\n" << 1 << "\n";
        return 0;
    }
    bfs(n);

    cout << visited[k] - 1 << "\n" << cnt[k] << "\n";

    return 0;
}