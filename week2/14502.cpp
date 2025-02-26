#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[10][10];
int visited[10][10];
int ret;
vector<pair<int,int>>wall;
vector<pair<int,int>>virus;
vector<int>sum;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void dfs(int y, int x){
    visited[y][x] = 1;
    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx]) continue;
        if (arr[ny][nx] == 1) continue;

        dfs(ny, nx);
    }
}

int spread(){
    memset(visited, 0, sizeof(visited));

    for (auto v : virus){
        dfs(v.first, v.second);
    }

    int cnt=0;
    // Calculate the number of 0s (safe zones)
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (arr[i][j] == 0 && visited[i][j] == 0){
                cnt++;
            }
        }
    }
    return cnt;
}

// (N x M) C 3
void build(){
    for (int i=0; i<wall.size(); i++){
        for (int j=0; j < i; j++){
            for (int k=0; k < j; k++){
                arr[wall[i].first][wall[i].second] = 1;
                arr[wall[j].first][wall[j].second] = 1;
                arr[wall[k].first][wall[k].second] = 1;

                ret = max(ret, spread());

                arr[wall[i].first][wall[i].second] = 0;
                arr[wall[j].first][wall[j].second] = 0;
                arr[wall[k].first][wall[k].second] = 0;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr[i][j];

            if (arr[i][j] == 0) wall.push_back({i,j});
            else if (arr[i][j] == 2) virus.push_back({i,j});
        }
    }

    build();

    cout << ret << "\n";

    return 0;
}