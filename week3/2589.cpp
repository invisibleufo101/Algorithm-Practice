#include <bits/stdc++.h>
using namespace std;
int n,m;
int mx = 0;
char arr[51][51];
int visited[51][51];
queue<pair<int,int>>q;
string s;
vector<pair<int,int>>lands;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void bfs(int y, int x){
    while (q.size()){
        tie(y,x) = q.front();
        q.pop();

        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx]) continue;
            if (arr[ny][nx] == 'W') continue;

            visited[ny][nx] = visited[y][x] + 1;
            mx = max(mx, visited[ny][nx]);
            q.push({ny, nx});
        }
    }
}

int main(){
    cin >> n >> m;

    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<m; j++){
            arr[i][j] = s[j];
            if (arr[i][j] == 'L') lands.push_back({i,j});
        }
    }

    for (auto land : lands){
        memset(visited, 0, sizeof(visited));
        visited[land.first][land.second] = 1;
        q.push({land.first, land.second});
        bfs(land.first, land.second);
    }

    cout << mx - 1 << "\n";

    return 0;
}