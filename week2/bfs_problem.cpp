#include <bits/stdc++.h>
using namespace std;
int n, m;
int start_y, start_x;
int end_y, end_x;
int y, x;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int visited[104][104];
int arr[104][104];

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (visited[ny][nx])
                continue;
            if (arr[ny][nx] == 0)
                continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    cin >> start_y >> start_x;
    cin >> end_y >> end_x;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    bfs(start_y, start_x);

    cout << visited[end_y][end_x] << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}