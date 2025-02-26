#include <bits/stdc++.h>
using namespace std;
int n, x;
int arr[104][104];
int visited[104][104];
int temp[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
map<int, int> mp;
vector<int> mx;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny > n || nx < 0 || nx > n)
            continue;
        if (visited[ny][nx])
            continue;
        if (temp[ny][nx] == 0)
            continue;

        dfs(ny, nx);
    }
    return;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            mp[arr[i][j]] = 1;
        }
    }
    
    for (auto h : mp) {        
        // Reset Ret, Visited, and Temp
        int ret = 0;
        memset(temp, 0, sizeof(temp));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (arr[i][j] >= h.first) {
                    temp[i][j] = 1;
                } else {
                    temp[i][j] = 0;
                }
            }
        }

        for (int i=0; i< n; i++){
            for (int j=0; j<n; j++){
                if (temp[i][j] && visited[i][j] == 0) {
                    dfs(i, j);
                    ret++;
                }
            }
        }
        mx.push_back(ret);
    }

    cout << *max_element(mx.begin(), mx.end()) << "\n";

    return 0;
}