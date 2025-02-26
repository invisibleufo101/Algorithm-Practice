#include <bits/stdc++.h>
using namespace std;
int n,m;
string x;
int arr[104][104];
int visited[104][104];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void bfs(int y, int x){
    queue<pair<int,int>>q;
    visited[y][x] = 1;
    q.push({y,x});
    while(q.size()){
        tie(y,x) = q.front();
        q.pop();
        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (!arr[ny][nx]) continue;
            if (visited[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    return;
}

int main(){
    cin >> n >> m;

    for (int i=0; i<n; i++){
        cin >> x;
        for (int j=0; j<m; j++){
            arr[i][j] = x[j] - '0';
        }
    }

    int start_y = 0, start_x = 0;
    int end_y = n-1, end_x = m-1;

    bfs(start_y, start_x);

    cout << visited[end_y][end_x] << "\n";

    return 0;
}