#include <bits/stdc++.h>
using namespace std;
int r,c;
string s;
char arr[21][21];
int visited[21][21];
int letters[26];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int cnt = 1;
int ret = 0;

/**
 * BackTrack problem
*/

int dfs(int y, int x){
    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if (visited[ny][nx]) continue;
        if (letters[arr[ny][nx] - 'A']) continue;

        letters[arr[ny][nx] - 'A']++;
        cnt++;

        ret = max(ret, cnt);

        dfs(ny, nx);

        letters[arr[ny][nx] - 'A'] = 0;
        cnt--;
        
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> r >> c;
    for (int i=0; i<r; i++){
        cin >> s;
        for (int j=0; j<c; j++){
            arr[i][j] = s[j];
        }
    }

    visited[0][0] = 1;
    letters[arr[0][0] - 'A']++;
    dfs(0,0);
    cout << ret << "\n";

    return 0;
}