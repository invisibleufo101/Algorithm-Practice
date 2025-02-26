#include <bits/stdc++.h>
using namespace std;

int mp[3][3], visited[3][3];

// Up, Right, Down, Left
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void solve(int y, int x){
    visited[y][x] = 1;
    // cout << "-----------\n";
    // cout << y << " , " << x << "\n";

    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3) continue; // If out of bounds
        if (visited[ny][nx]) continue; // If already visited
        if (mp[ny][nx] == 0) continue; // If the path is not crossable

        solve(ny, nx);
    }
    return;
}

int main(){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cin >> mp[i][j];
        }
    }

    solve(0, 0);

    return 0;
}