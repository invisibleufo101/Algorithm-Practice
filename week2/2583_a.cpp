#include <bits/stdc++.h>
using namespace std;
int m,n,k,ret,area;
int left_x, left_y, right_x, right_y;
int arr[101][101];
int visited[101][101];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
vector<int>v;

void print(int a[101][101]){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(int y, int x){
    area++;
    visited[y][x] = 1;
    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if (visited[ny][nx]) continue;
        if (arr[ny][nx]) continue;

        dfs(ny, nx);
    }
}

int main(){
    cin >> m >> n >> k;
    while (k--){
        cin >> left_x >> left_y >> right_x >> right_y;
        for (int i=left_y; i<right_y; i++){
            for (int j=left_x; j<right_x; j++){
                arr[i][j] = 1;
            }
        }
    }

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (arr[i][j] == 0 && visited[i][j] == 0){
                area = 0;
                ret++;
                dfs(i,j);
                v.push_back(area);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << ret << "\n";

    for (int i : v) cout << i << " ";
    
    return 0;
}