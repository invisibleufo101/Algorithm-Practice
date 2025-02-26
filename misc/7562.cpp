#include <bits/stdc++.h>
using namespace std;
int t,n;
int ky, kx, ty, tx;
int arr[301][301];
int visited[301][301];
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(int y, int x){
    visited[y][x] = 1;
    queue<pair<int,int>>q;
    q.push({y,x});
    while (q.size()){
        tie(y,x) = q.front();
        q.pop();
        for (int i=0; i<8; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (visited[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while (t--){
        cin >> n;
        cin >> ky >> kx >> ty >> tx;

        memset(visited, 0, sizeof(visited));
        bfs(ky, kx);
        cout << visited[ty][tx] - 1 << "\n";
    }
    return 0;
}