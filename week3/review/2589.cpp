#include <bits/stdc++.h>
using namespace std;
int r,c;
char arr[51][51];
int visited[51][51];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
vector<pair<int,int>>lands;
queue<pair<int,int>>q;
int max_dist = 0;

/**
 * Main logic for this problem:
 * - Get the coord of all lands
 * - Iterate through each one of them
 * - Using BFS, get the greatest distance that each coordinate could possibly have
 *      * Maximum distance value is updated for EVERY step in each individual coordinate
 * - Print out the max distance found
*/

void bfs(int y, int x){
    while (q.size()){
        tie(y,x) = q.front();
        q.pop();

        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if (visited[ny][nx]) continue;
            if (arr[ny][nx] == 'W') continue;

            visited[ny][nx] = visited[y][x] + 1;
            max_dist = max(max_dist, visited[ny][nx]);
            q.push({ny, nx});
        }
    }
    return;
}

int main(){
    cin >> r >> c;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 'L') lands.push_back({i,j});
        }
    }

    for (auto land : lands){
        memset(visited, 0, sizeof(visited));
        visited[land.first][land.second] = 1;
        q.push({land.first, land.second});
        bfs(land.first, land.second);
    }

    cout << max_dist -1 << "\n";

    return 0;
}