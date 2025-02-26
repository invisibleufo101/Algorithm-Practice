#include <bits/stdc++.h>
using namespace std;
int r,c;
int cnt;
int ret=0;
string s;
char arr[21][21];
int visited[21][21];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int letters[26];


int search(int y, int x){

    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if (visited[ny][nx]) continue;
        if (letters[arr[ny][nx] - 'A']) continue;

        visited[ny][nx] = 1;
        letters[arr[ny][nx] - 'A'] = 1;
        cnt++;

        ret = max(ret, cnt);

        search(ny, nx);

        visited[ny][nx] = 0;
        letters[arr[ny][nx] - 'A'] = 0;
        cnt--;
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;
    for (int i=0; i<r; i++){
        cin >> s;
        for (int j=0; j<c; j++){
            arr[i][j] = s[j];
        }
    }

    int y=0, x=0;
    visited[y][x] = 1;
    letters[arr[y][x] - 'A'] = 1;

    search(y,x);

    cout << ret + 1 << "\n";

    return 0;
}