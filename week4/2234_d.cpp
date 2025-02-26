#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[51][51];
int visited[51][51];
int compSize[2504];
int dy[] = {0,-1,0,1};
int dx[] = {-1,0,1,0};

int dfs(int y, int x, int cnt){
    if (visited[y][x]) return 0;

    visited[y][x] = 1;
    int ret = 1;
    for (int i=0; i<4; i++){
        if (!(arr[y][x]) & (1 << i)){
            int ny = y + dy[i];
            int nx = x + dx[i];

            ret += dfs(ny, nx, cnt);
        }
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (!visited[i][j]){


            }
        }
    }



    return 0;
}