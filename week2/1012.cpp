#include <bits/stdc++.h>
using namespace std;
int t, m, n, k;
int bae_x, bae_y;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int arr[54][54];
int visited[54][54];

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if (visited[ny][nx])
            continue;
        if (arr[ny][nx] == 0)
            continue;

        dfs(ny, nx);
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> m >> n >> k;
        int ret = 0;
        memset(arr, 0, sizeof(arr)); // <- Kinda figured this one out...
        memset(visited, 0, sizeof(visited)); // <- THIS WAS THE REAL KICKER

        while (k--) {
            cin >> bae_x >> bae_y;
            arr[bae_y][bae_x] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] && visited[i][j] == 0) {
                    ret++;
                    dfs(i, j);
                }
            }
        }

        cout << ret << "\n";
    }
    return 0;
}