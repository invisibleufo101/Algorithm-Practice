#include <bits/stdc++.h>
using namespace std;
int n, m, y, x;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int cnt=0;
int arr[104][104];
int visited[104][104];

void dfs(int y, int x){
    visited[y][x] = 1;

    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (visited[ny][nx]) continue;
        if (arr[ny][nx] == 0) continue;

        dfs(ny, nx);
    }
}

int main(){
    cin >> n >> m;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (arr[i][j] && !visited[i][j]){
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}