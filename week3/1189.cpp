#include <bits/stdc++.h>
using namespace std;
int r,c,k;
string s;
int arr[6][6];
int visited[6][6];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int ret = 0;
int step;

void print(int a[6][6]){
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(int y, int x){
    if (y == 0 && x == c-1){
        cout << "Final step: " << step << "\n";
        if (step == k) ret++;
        return;
    }

    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if (visited[ny][nx]) continue;
        if (arr[ny][nx] == 0) continue;

        visited[ny][nx] = 1;
        step++;

        cout << step << "\n";

        dfs(ny, nx);

        visited[ny][nx] = 0;
        step--;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c >> k;
    for (int i=0; i<r; i++){
        cin >> s;
        for (int j=0; j<c; j++){
            if (s[j] == '.') arr[i][j] = 1;
            else if (s[j] == 'T') arr[i][j] = 0;
        }
    }

    step = 1;
    visited[r-1][0] = 1;
    dfs(r-1, 0);

    cout << ret << "\n";

    return 0;
}